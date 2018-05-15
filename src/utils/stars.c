/* PWB GENERAL UTILITIES
* Stellar characterization and generation
*
* Revision I (01/18) (C) NFINIT Systems 2018
* Author: ict (ict@nfinit.systems)
*
* This file provides functions for characterizing and
* generating random properties of stars
*/

#include <stdlib.h>
#include "../../include/stars.h"
#include "../../include/star_arrays.h"

/* External definitions */
extern double SPECTRAL_TEMP[];
extern char* SPECTRAL_STR[];

/* Determine a spectral type and subtype based on input temperature
 */
spectype_T infer_type(double temperature, temp_T unit)
{
	/* Declare starting variables */
	int i, t;
	/* Convert input temperature to Kelvin */
	t = convert_temp(temperature,unit,KELVIN); 
	/* Check supplied arguments */
	if (t < 0 || unit == NO_TEMP_UNIT) return NO_TYPE;
	/* Use the SPECTRAL_TEMP array to find the primary type */
	for (i = 0; i < sizeof(SPECTRAL_TEMP); i++)
		if (t >= SPECTRAL_TEMP[i]) break;
	return i;
}

/* Determines the subtype given the spectral type and temperature
 */
int infer_subtype(double temperature, temp_T unit, spectype_T type)
{
	/* Declare starting variables */
	int i, s, f;
	double t, l, u, r, d, c;
	/* Convert input temperature to Kelvin */
	t = convert_temp(temperature,unit,KELVIN); 
	/* Check supplied arguments */
	if (unit == NO_TEMP_UNIT || type == NO_TYPE) return 0;
	/* Use the SPECTRAL_TEMP array to determine the range */
	l = SPECTRAL_TEMP[type];
	if (type != O) {
		u = SPECTRAL_TEMP[type-1];
	} else {
		u = MAX_STAR_TEMP;
	}
	r = u-l;

	/* Set the type interval divisor */ 
	f = 10;
	if (type == O) f = 10-EARLY_O;
	/* Divide the range into f equal segments */
		d = r/f;
	/* Determine subtype by testing the input against
         * successive intervals
	 */
	for (i = 1; i <= f; i++)
	{
		c = l + i * d;
		if (t <= c) break;
	}
	return 10-i;
}

/* Gets a string corresponding to the given spectral type
 * from the main type string array
 */
char *spectype_T_string(spectype_T t)
{
	if (t >= 0 && t <= NUM_SPECTRAL_TYPES) return SPECTRAL_STR[t];	
	return SPECTRAL_STR[NUM_SPECTRAL_TYPES];
}

/* Retrieves the mass value from a star structure and automatically converts
 * it to the desired unit (to avoid conversion errors from forgotten units)
 */
double get_mass(star_T *star, mass_T unit)
{
	if (star == NULL) return 0.0;
	if (unit >= NO_MASS_UNIT || unit <= 0) return 0.0;
	return convert_mass(star->mass,kg,unit);
}
