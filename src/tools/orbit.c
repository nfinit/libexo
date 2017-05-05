/* PWB COMMAND-LINE FRONTEND UTILITIES
 * Orbital characterization utility
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This program provides a simple front-end for the orbital computation
 * facilities of the Planetary Workbench, allowing for conversion between
 * orbital periods, semimajor axes, and combined host-satellite masses based
 * on known data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/units.h"
#include "../../include/orbits.h"

/* output string constants */
#define HELP_STR "usage: \
<number> <unit> \
<host mass> <unit> \
<companion mass> <unit>"

/* enumerations, prototypes and other useful definitions */
enum conversion_type {sma_period, period_sma, conv_error};
typedef enum conversion_type convtype;
convtype get_conv(char *arg);
void print_unit_info();

/* MAIN FUNCTION
 * Takes the following arguments:
 * <number> <unit> <host mass> <unit> <companion mass> <unit>
 */
int main (int argc, char *argv[])
{
	/* check that proper arguments have been supplied */
	if (argc < 7 || argc > 7) 
	{
		printf("%s\n",HELP_STR);
		return 0;
	}

	/* variable declaration and initialization */
	double n = 0.0; /* primary value to evaluate */
	double nc = 0.0; /* converted value (into seconds or meters) */
	double hm = 0.0; /* host mass */
	double hc = 0.0; /* host mass in kilograms */
	double cm = 0.0; /* companion mass */
	double cc = 0.0; /* companion mass in kilograms */
	double r = 0.0; /* computation result */
	double rc = 0.0; /* human-readable computation result */
	convtype conv = conv_error; /* calculation/conversion to perform */
	smaunit su = NO_SMA_UNIT; /* unit of the primary value if SmA */
	perunit pu = NO_PER_UNIT; /* unit of the primary value if period */
	massunit hu = NO_MASS_UNIT; /* units of the host mass */
	massunit cu = NO_MASS_UNIT; /* units of the companion mass */
	char *out_str;

	/* parse number to convert */
	n = atof(argv[1]);

	/* determine conversion type */
	conv = get_conv(argv[2]);

	/* parse first unit of input */
	switch (conv) {
		case sma_period:
			su = parse_sma_unit(argv[2]);				
			break;
		case period_sma:
			pu = parse_per_unit(argv[2]);
			break;
		default:
			print_unit_info();		
			printf("%s\n",HELP_STR);
			return 0;
	}

	/* parse first mass */
	hm = atof(argv[3]);

	/* parse first mass unit */
	hu = parse_mass_unit(argv[4]);

	/* parse second mass */
	cm = atof(argv[5]);

	/* parse second mass unit */
	cu = parse_mass_unit(argv[6]);

	/* convert primary value to proper argument for computation */
	switch (conv) {
		case sma_period:
			nc = convert_smaunit(n,su,m);
			break;
		case period_sma:
			nc = convert_perunit(n,pu,seconds);
			break;
		default:
			print_unit_info();		
			printf("%s\n",HELP_STR);
			return 0;
	}

	/* convert host/companion masses to kilograms */
	hc = convert_massunit(hm,hu,kg);
	cc = convert_massunit(cm,cu,kg);

	/* compute result */
	switch (conv) {
		case sma_period:
			r = period(nc,hc,cc);
			break;
		case period_sma:
			r = sma(nc,hc,cc);
			break;
		default:
			print_unit_info();		
			printf("%s\n",HELP_STR);
			return 0;
	}

	/* convert result */
	switch (conv) {
		case sma_period:
			pu = select_perunit(r);
			out_str = perunit_string(pu);
			rc = convert_perunit(r,seconds,pu);
			break;
		case period_sma:
			su = select_smaunit(r);
			out_str = smaunit_string(su);
			rc = convert_smaunit(r,m,su);
			break;
		default:
			print_unit_info();		
			printf("%s\n",HELP_STR);
			return 0;
	}

	/* print result for user */
	printf("%f %s\n",rc,out_str);
	
	/* computation is done */
	return 0;
}

/* Parses arguments to get a conversion type to pass to the main function
 */
convtype get_conv(char *arg)
{
	/* declare variables */
	smaunit s = NO_SMA_UNIT;
	perunit p = NO_PER_UNIT;
	convtype r = conv_error;

	/* attempt to parse an SMA first */ 
	s = parse_sma_unit(arg);

	/* check if result was valid */
	if (s != NO_SMA_UNIT) {
		r = sma_period;
	}
	
	/* attempt to parse a period next */
	p = parse_per_unit(arg);

	/* check if result was valid */
	if (p != NO_PER_UNIT) {
		r = period_sma;
	}

	/* if we get here, no valid unit was entered */
	return r;
}

/* Prints unit info and frees supported unit strings
 */
void print_unit_info()
{
	char *sup_sma = supported_sma_units();
	char *sup_per = supported_per_units();
	char *sup_mass = supported_mass_units();
	printf("%s\n","An invalid unit was entered, please try again with a different measurement.");
	printf("%s\n","The workbench can work with measurements in the following units:");
	printf("%s%s\n","Length: ",supported_sma_units());
	printf("%s%s\n","Time: ",supported_per_units());
	printf("%s%s\n","Mass: ",supported_mass_units());
	free(sup_sma);
	free(sup_per);
	free(sup_mass);
}
