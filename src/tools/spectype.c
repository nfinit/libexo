/* PWB COMMAND-LINE FRONTEND UTILITIES
 * <name/description of utility>
 *
 * Revision II (01/18) (C) NFINIT Systems 2018
 * Author: ict (ict@nfinit.systems)
 *
 * <long description of utility>
 *
 * Based on the revision II PWB driver foundation (skel.c)
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include "../../include/stars.h"

/* useful definitions */
#define MIN_ARGS 3
#define MAX_ARGS 3
#define IN_RANGE(x) (x < MIN_ARGS || x > MAX_ARGS) 
#define USAGE_STR "usage: spectype <temperature> <unit>"

/* argument locations for quick redefinition */
#define TEMP_IN 1
#define UNIT_IN 2

/* USAGE STRING PRINTER
 * Prints any usage information for the program
 */
void print_usage ()
{
	printf("%s\n",USAGE_STR);
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
	double t;	/* input temperature */ 
	temp_T iu; 	/* input temperature unit */
	spectype_T s; 	/* derived spectral type */
	int d; 		/* derived spectral subtype */

	/* check that correct number of arguments have been supplied */
	if (!check_args(argc)) { print_usage(); return 0; }

	/* initialize variables */
	t= 0.0;
	iu = NO_TEMP_UNIT;
	s = NO_TYPE;
	d = 0;


	/* parse temperature value and unit */
	t = atof(argv[TEMP_IN]);
	iu = parse_temp_unit(argv[UNIT_IN]);

	/* infer spectral type based on processed value */
	s = infer_type(t,iu);
	d = infer_subtype(t,iu,s);	

	/* print result */
	printf("Spectral type: %s%d\n",spectype_T_string(s),d);

	/* program is done, return status */
	return 0;
}
