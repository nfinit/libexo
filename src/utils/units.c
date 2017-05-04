/* PWB GENERAL UTILITIES
 * Unit parsing and conversion
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides functions for parsing and conversion of
 * supported units
 */

#include <string.h>
#include "../../include/units.h"
#include "../../include/unit_arrays.h"

/* Parse a string to an SmA unit
 */
smaunit parse_sma_unit(char *arg)
{
	/* declare variables */
	int i;
	smaunit r;

	/* iterate through SMA unit array */
	for (i = 0; i < NUM_SMA_UNITS; i++)
	{
		if (strcmp(arg, sma_units[i]) == 0) {
			r = i;
			break;
		} else if (strcmp(arg, sma_units[i+NUM_SMA_UNITS]) == 0) {
			r = i;
			break;
		} else {
			r = NO_SMA_UNIT;
		}
		
	}

	/* return result */
	return r;

}

/* Parse a string to a period unit
 */
perunit parse_per_unit(char *arg)
{
	/* declare variables */
	int i;
	perunit r;

	/* iterate through period unit array */
	for (i = 0; i < NUM_PER_UNITS; i++)
	{
		if (strcmp(arg, per_units[i]) == 0) {
			r = i;
			break;
		} else {
			r = NO_PER_UNIT;
		}
	}

	/* return result */
	return r;
}

double convert_smaunit(double sma, smaunit in, smaunit out)
{
	if (in < 0 || in > NUM_SMA_UNITS) {
		return -1;
	} else if (out < 0 || out > NUM_SMA_UNITS) {
		return -1;
	} else {
		return sma * sma_table[in][out];
	}
	return -1;
}

double convert_perunit(double per, perunit in, perunit out)
{
        if (in < 0 || in > NUM_PER_UNITS) {
                return -1;
        } else if (out < 0 || out > NUM_PER_UNITS) {
                return -1;
        } else {
                return per * per_table[in][out];
        }
        return -1;	
}
