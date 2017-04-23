#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "orbits.h"

/* mode enumeration */
enum mode { sma, period };

/* function prototypes */
void printhelp();
enum mode set_mode(char *arg);
enum time_units set_period_units(char *arg);
enum orbital_units set_sma_units(char *arg);

/* MAIN FUNCTION
 */
int main (int argc, char *argv[])
{
	char *orbit_unit;
	char *time_unit;
	enum orbital_units ou;
	enum time_units pu;
	enum mode mode;
	double input;
	double result;
	double output;

	/* check if arguments were provided */
	if (argc < 2 || argc > 4) {
		printhelp();
		return 0;
	}

	/* set program mode */
	mode = set_mode(argv[1]);

	/* get number to convert */
	switch (mode) {
		case sma:
			input = strtod(argv[2],NULL);
		case period:
			input = strtod(argv[1],NULL);
	}	

	/* determine input units */
	if (argc > 2) {
		switch (mode) {
			case sma:
				pu = set_period_units(argv[3]);
				time_unit = argv[3];
			case period:
				ou = set_sma_units(argv[2]);
				orbit_unit = argv[2];
		}
	} else {
		pu = years;
		ou = AU;
		time_unit = "years";
		orbit_unit = "AU";
	}

	/* compute result */
	switch (mode) {
		case sma:
			result = period_to_sma(input, pu, AU);
		case period:
			result = sma_to_period(input, ou, years);
	}	

	/* determine output units and print results */
	if (mode == sma) {

		if (result < 0.01) {
			output = sma_conv(result, ou, km);
			orbit_unit = "km";
		} else {
			output = result;
		}

		if (input == 1) {
			switch (pu) {
				case years:
					time_unit = "year";
				case days:
					time_unit = "day";
				case hours:
					time_unit = "hour";
				case minutes:
					time_unit = "minute";
				case seconds:
					time_unit = "second";
			}
		}

		printf("Semimajor axis of an orbit with period %f %s: %f %s\n", input, time_unit, output, orbit_unit);

	} else if (mode == period) {

		if (result < 0.5) {
			output = per_conv(result, pu, days);
			time_unit = "days";
		} else {
			output = result;
			time_unit = "years";
		}

		printf("Period of an orbit with semimajor axis of %f %s: %f %s\n", input, orbit_unit, output, time_unit);
	} 

	return 0;
}

/* Return an operation mode based on input
 * Default: Orbital period from semimajor axis
 */
enum mode set_mode (char *arg) 
{
	enum mode mode;
	mode = period;

	if (strcmp(arg,"sma") == 0) {
		mode = sma;
	}

	return mode;
}

/* Return appropriate time units based on input
 * Default: years
 */
enum time_units set_period_units (char *arg) 
{
	enum time_units pu;
	pu = years;

	if (strcmp(arg,"year") == 0) {
		pu = years;
	} else if (strcmp(arg,"days") == 0) {
		pu = days;
	} else if (strcmp(arg,"hours")) {
		pu = hours;
	} else if (strcmp(arg,"minutes")) {
		pu = minutes;
	} else if (strcmp(arg,"seconds")) {
		pu = seconds;
	}

	return pu;
}

/* Return appropriate orbital distance units based on input
 * Default: Astronomical units
 */
enum orbital_units set_sma_units (char *arg) 
{
	enum orbital_units ou;

	if (strcmp(arg,"AU") == 0) {
		ou = AU;
	} else if (strcmp(arg,"km") == 0) {
		ou = km;
	} else if (strcmp(arg,"mi") == 0) {
		ou = mi;
	}

	return ou;
}

void printhelp ()
{
	printf("Usage: orbit [sma] <number> [units]\n");
}
