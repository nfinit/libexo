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

/* Parse a string to a mass unit
 */
massunit parse_mass_unit(char *arg)
{
	/* declare variables */
	int i;
	massunit r;

	/* iterate through mass unit array */
	for (i = 0; i < NUM_MASS_UNITS; i++)
	{
		if (strcmp(arg, mass_units[i]) == 0) {
			r = i;
			break;
		} else if (strcmp(arg, mass_units[i+NUM_MASS_UNITS]) == 0) {
			r = i;
			break;
		} else {
			r = NO_MASS_UNIT;
		}
		
	}

	/* return result */
	return r;

}

/* Convert between units of distance in semimajor axes
 */
double convert_smaunit(double sma, smaunit in, smaunit out)
{
	/* check if the provided unit was out of bounds */
	if (in < 0 || in > NUM_SMA_UNITS) {
		return -1;
	} else if (out < 0 || out > NUM_SMA_UNITS) {
		return -1;
	} else {
		/* multiply by conversion value and return */
		return sma * sma_table[in][out];
	}

	/* we shouldn't get here */
	return -1;
}

/* Convert between units of time in orbital periods
 */
double convert_perunit(double per, perunit in, perunit out)
{
	/* check if the provided unit was out of bounds */
        if (in < 0 || in > NUM_PER_UNITS) {
                return -1;
        } else if (out < 0 || out > NUM_PER_UNITS) {
                return -1;
        } else {
		/* multiply by conversion value and return */
                return per * per_table[in][out];
        }

	/* we shouldn't get here */
        return -1;	
}

/* Convert between units of mass
 */
double convert_massunit(double mass, massunit in, massunit out)
{
	/* check if the provided unit was out of bounds */
	if (in < 0 || in > NUM_MASS_UNITS) {
		return -1;
	} else if (out < 0 || out > NUM_MASS_UNITS) {
		return -1;
	} else {
		/* multiply by conversion value and return */
		return mass * mass_table[in][out];
	}

	/* we shouldn't get here */
	return -1;
}
