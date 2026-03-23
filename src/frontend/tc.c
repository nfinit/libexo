/* PWB COMMAND-LINE FRONTEND UTILITIES
 * Temperature conversion utility
 *
 * Revision I (01/18) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This program allows the user to convert between a number of temperatures
 * including Kelvin, Celsius and Faranheit.
 *
 * Based on the revision II PWB driver foundation.
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../include/units.h"

/* useful definitions */
#define MIN_ARGS 4
#define MAX_ARGS 4
#define EQ_ARGS (MIN_ARGS == MAX_ARGS)
#define IN_RANGE(x) (x < MIN_ARGS || x > MAX_ARGS) 
#define USAGE_STR "usage: tc <temperature> <input unit> <output unit>"

/* argument locations for quick redefintion */
#define TEMP_IN 1
#define UNIT_IN 2
#define UNIT_OUT 3

/* enumerations and useful prototypes */
void print_unit_info();

/* USAGE STRING PRINTER
 * Prints any usage information for the program
 */
void print_usage ()
{
	printf("%s\n",USAGE_STR);
	print_unit_info();
	return;
}

/* ARGUMENT CHECKER
 * Checks arguments using a preprocessor-defined method based on
 * the values MIN_ARGS and MAX_ARGS
 */
int check_args (int argc)
{
	if IN_RANGE(argc) return 0;
	return 1;
}

/* MAIN FUNCTION
 * Takes program arguments and passes them to core functions
 */
int main (int argc, char *argv[])
{
	/* declare variables */
	double t; /* input temperature */
	double v; /* output temperature */
	temp_T iu; /* input unit */
	temp_T ou; /* output unit */

	/* initialize variables */
	t = v = 0.0;
	iu = ou = NO_TEMP_UNIT;
	
	/* check that correct number of arguments have been supplied */
	if (!check_args(argc)) { print_usage(); return 0; }

	/* parse temperature value */
	t = atof(argv[TEMP_IN]);

	/* parse units to convert */
	iu = parse_temp_unit(argv[UNIT_IN]);
	ou = parse_temp_unit(argv[UNIT_OUT]);
	if (iu == NO_TEMP_UNIT || ou == NO_TEMP_UNIT) 
	{ 
		printf("Invalid units entered.\n");
		print_usage();
		return 0; 
	}

	/* perform conversion */
	v = convert_temp(t,iu,ou);	

	/* print result */
	printf("%f %s\n",v,argv[UNIT_OUT]);

	/* program is done, return status */
	return 0;
}

void print_unit_info()
{
	char *sup_units = supported_temp_units();
	printf("%s\n","This program supports the following units:");
	printf("%s\n",sup_units);
	free(sup_units);
}
