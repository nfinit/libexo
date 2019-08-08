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

/* useful definitions */
#define MIN_ARGS 1
#define MAX_ARGS 1
#define IN_RANGE(x) (x < MIN_ARGS || x > MAX_ARGS) 
#define USAGE_STR "usage: <program> <arguments>"

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
	/* check that correct number of arguments have been supplied */
	if (!check_args(argc)) { print_usage(); return 0; }

	/* program is done, return status */
	return 0;
}
