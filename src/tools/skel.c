/* PWD COMMAND-LINE FRONTEND UTILITIES
 * Driver skeleton
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This is a simple skeleton for a "driver" program
 * that can be used to test code functionality
 */

/* includes */
#include <stdio.h>

/* useful definitions */
#define MIN_ARGS 1
#define MAX_ARGS 1
#define USAGE_STR "usage: <program> <arguments>"

/* MAIN FUNCTION
 * Takes program arguments and passes them to core functions
 */

int main (int argc, char *argv[])
{
	/* check that proper arguments have been supplied */
	if (argc < MIN_ARGS || argc > MAX_ARGS)
	{
		printf("%s\n",USAGE_STR);
		return 0;
	}

	/* program is done, return status */
	return 0;
}
