/* PWB GENERAL UTILITIES
 * Unit parsing and conversion
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides functions for parsing and conversion of
 * supported units
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/units.h"
#include "../../include/unit_arrays.h"

/* Parse a string to an SmA unit
 */
length_T parse_sma_unit(char *arg)
{
	/* declare variables */
	int i;
	length_T r;

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
time_T parse_per_unit(char *arg)
{
	/* declare variables */
	int i;
	time_T r;

	/* iterate through period unit array */
	for (i = 0; i < NUM_PER_UNITS; i++)
	{
		if (strcmp(arg, per_units[i]) == 0) {
			r = i;
			break;
		} else if (strcmp(arg, per_units[i+NUM_PER_UNITS]) == 0) {
			r = i;
			break;
		} else if (strcmp(arg, per_units[i+(NUM_PER_UNITS*2)]) == 0) {
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
mass_T parse_mass_unit(char *arg)
{
	/* declare variables */
	int i;
	mass_T r;

	/* iterate through mass unit array */
	for (i = 0; i < NUM_MASS_UNITS; i++)
	{
		if (strcmp(arg, mass_units[i]) == 0) {
			r = i;
			break;
		} else if (strcmp(arg, mass_units[i+NUM_MASS_UNITS]) == 0) {
			r = i;
			break;
		} else if (strcmp(arg, mass_units[i+(NUM_MASS_UNITS*2)]) == 0) {
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
double convert_length(double sma, length_T in, length_T out)
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
double convert_time(double per, time_T in, time_T out)
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
double convert_mass(double mass, mass_T in, mass_T out)
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

char *supported_sma_units()
{
	/* declare variables */
	int i;
	char* r = malloc(80 * sizeof(char));

	/* iterate through supported units */
	for (i = 0; i < NUM_SMA_UNITS; i++)
	{
		strcat(r, sma_units[i]);
		if (i != NUM_SMA_UNITS-1) {
			if (strlen(r) + strlen(sma_units[i+1]) >= 80-1 ) break;
			strcat(r, ", ");
		}
	}

	/* return completed string */
	return r;	
}

char *supported_per_units()
{
	/* declare variables */
	int i;
	char* r = malloc(80 * sizeof(char));

	/* iterate through supported units */
	for (i = 0; i < NUM_PER_UNITS; i++)
	{
		strcat(r, per_units[i]);
		if (i != NUM_PER_UNITS-1) {
			if (strlen(r) + strlen(per_units[i+1]) >= 80-1 ) break;
			strcat(r, ", ");
		}
	}

	/* return completed string */
	return r;	
}

char *supported_mass_units()
{
	/* declare variables */
	int i;
	char* r = malloc(80 * sizeof(char));

	/* iterate through supported units */
	for (i = 0; i < NUM_MASS_UNITS; i++)
	{
		strcat(r, mass_units[i]);
		if (i != NUM_MASS_UNITS-1) {
			if (strlen(r) + strlen(mass_units[i+1]) >= 80-1 ) break;
			strcat(r, ", ");
		}
	}

	/* return completed string */
	return r;	
}

/* Automatically selects a unit based on an input in seconds
 */
time_T select_time_T(double p)
{
	if (p < per_table[minutes][seconds]) return seconds;
	if (p < per_table[hours][seconds]) return minutes;
	if (p < per_table[days][seconds]) return hours;
	if (p < (per_table[years][seconds] * 0.6)) return days;
	return years;
}

/* Automatically selects a unit based on an input in meters
 */
length_T select_length_T(double s)
{
	if (s < sma_table[km][m]) return m;
	if (s < (sma_table[AU][m] * 0.05)) return km;
	return AU;
}

/* Gets a string corresponding to the given unit from the 
 * main time measurement string array
 */
char *time_T_string(time_T p)
{
	if (p < 0) return per_units[0];
	if (p >= NUM_PER_UNITS) return per_units[NUM_PER_UNITS-1];
	return per_units[p];	
}

/* Gets a string corresponding to the given unit from the 
 * main length measurement string array
 */
char *length_T_string(length_T s)
{
	if (s < 0) return sma_units[0];
	if (s >= NUM_SMA_UNITS) return sma_units[NUM_SMA_UNITS-1];
	return sma_units[s];	
}
