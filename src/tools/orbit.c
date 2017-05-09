/* PWB COMMAND-LINE FRONTEND UTILITIES
 * Orbital characterization utility
 *
 * Revision II (05/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This program provides a simple front-end for the orbital computation
 * facilities of the Planetary Workbench, allowing for conversion between
 * orbital periods, semimajor axes, combined host-satellite masses,
 * aphelion and perihelion distances, based on known data.
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
<companion mass> <unit>\n\
       \
<SmA> <unit> \
<\"perihelion\"|\"aphelion\"> \
<eccentricity>"

/* enumerations, prototypes and other useful definitions */
enum conversion_type {sma_period, period_sma, e_peri, e_aph, conv_error};
typedef enum conversion_type conv_T;
conv_T get_conv(char *arg);
void print_unit_info();

/* MAIN FUNCTION
 * Takes the following arguments:
 * <number> <unit> <host mass> <unit> <companion mass> <unit>
 * <SmA> <unit> <perihelion|aphelion> <eccentricity>
 */
int main (int argc, char *argv[])
{
	/* check that proper arguments have been supplied */
	if (argc < 5 || argc > 7) 
	{
		printf("%s\n",HELP_STR);
		return 0;
	}

	/* variable declaration and initialization */
	double e = 0.0; /* eccentricity */
	double n = 0.0; /* primary value to evaluate */
	double nc = 0.0; /* converted value (into seconds or meters) */
	double hm = 0.0; /* host mass */
	double hc = 0.0; /* host mass in kilograms */
	double cm = 0.0; /* companion mass */
	double cc = 0.0; /* companion mass in kilograms */
	double r = 0.0; /* computation result */
	double rc = 0.0; /* human-readable computation result */
	conv_T conv = conv_error; /* calculation/conversion to perform */
	length_T su = NO_SMA_UNIT; /* unit of the primary value if SmA */
	time_T pu = NO_PER_UNIT; /* unit of the primary value if period */
	mass_T hu = NO_MASS_UNIT; /* units of the host mass */
	mass_T cu = NO_MASS_UNIT; /* units of the companion mass */
	char *out_str;

	/* parse number to convert */
	n = atof(argv[1]);

	/* determine conversion type */
	conv = get_conv(argv[3]); /* check for eccentricity */
	if (conv == conv_error) conv = get_conv(argv[2]);

	/* parse first unit of input */
	switch (conv) {
		case sma_period:
			su = parse_sma_unit(argv[2]);				
			break;
		case period_sma:
			pu = parse_per_unit(argv[2]);
			break;
		case e_peri:
			e = atof(argv[4]);
			su = parse_sma_unit(argv[2]);
			break;
		case e_aph:
			e = atof(argv[4]);
			su = parse_sma_unit(argv[2]);
			break;
		default:
			print_unit_info();		
			printf("%s\n",HELP_STR);
			return 0;
	}

	/* parse first mass */
	if (!e) hm = atof(argv[3]);

	/* parse first mass unit */
	if (!e) hu = parse_mass_unit(argv[4]);

	/* parse second mass */
	if (!e) cm = atof(argv[5]);

	/* parse second mass unit */
	if (!e) cu = parse_mass_unit(argv[6]);

	/* convert primary value to proper argument for computation */
	switch (conv) {
		case sma_period:
			nc = convert_length(n,su,m);
			break;
		case period_sma:
			nc = convert_time(n,pu,seconds);
			break;
		case e_peri:
			nc = convert_length(n,su,m);
			break;
		case e_aph:
			nc = convert_length(n,su,m);
			break;
		default:
			print_unit_info();		
			printf("%s\n",HELP_STR);
			return 0;
	}

	/* convert host/companion masses to kilograms */
	if (!e) hc = convert_mass(hm,hu,kg);
	if (!e) cc = convert_mass(cm,cu,kg);

	/* compute result */
	switch (conv) {
		case sma_period:
			r = period(nc, hc, cc);
			break;
		case period_sma:
			r = sma(nc, hc, cc);
			break;
		case e_peri:
			r = perihelion(nc, e); 
			break;
		case e_aph:
			r = aphelion(nc, e); 
			break;
		default:
			print_unit_info();		
			printf("%s\n",HELP_STR);
			return 0;
	}

	/* convert result */
	switch (conv) {
		case sma_period:
			pu = select_time_T(r);
			out_str = time_T_string(pu);
			rc = convert_time(r, seconds, pu);
			break;
		case period_sma:
			su = select_length_T(r);
			out_str = length_T_string(su);
			rc = convert_length(r, m, su);
			break;
		case e_peri:
			out_str = length_T_string(su);
			rc = convert_length(r, m, su); 
			break;
		case e_aph:
			out_str = length_T_string(su);
			rc = convert_length(r, m, su); 
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
conv_T get_conv(char *arg)
{
	/* declare variables */
	length_T s = NO_SMA_UNIT;
	time_T p = NO_PER_UNIT;
	conv_T r = conv_error;

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

	/* attempt to parse a perihelion/aphelion conversion */
	if (strcmp(arg, "aphelion") == 0) {
		r = e_aph;
	} else if (strcmp(arg, "perihelion") == 0) {
		r = e_peri;
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
