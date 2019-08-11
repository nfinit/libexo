/* LIBEXO STELLAR UTILITIES
*
* Revision I (08/19) (C) NFINIT Systems 2019
* Author: ict (ict@nfinit.systems)
*
* This file provides mathematical routines for characterizing stars
*/

#include <math.h>
#include "stars.h"

/* Procedure for deriving a bolometric correction given stellar effective
 * temperature, based on methods presented by Phillip Flower with 
 * corrected coefficient values obtained from Flower by Guillermo Torres
 */
double bcv(double temperature, temp_T unit)
{
	/* Declare starting variables */
	double t,logt;
	/* Convert input temperature to Kelvin */
	t = convert_temp(temperature,unit,KELVIN); 
	/* Check supplied arguments */
	if (t < 0 || unit == NO_TEMP_UNIT) return 0;
	/* Begin computation */
	logt = log10(t);
	if (logt < 3.70) return BCA1+(BCB1*logt)+(BCC1*pow(logt,2))+(BCD1*pow(logt,3));
	if (logt < 3.90) return BCA2+(BCB2*logt)+(BCC2*pow(logt,2))+(BCD2*pow(logt,3))+(BCE2*pow(logt,4));
	return BCA3+(BCB3*logt)+(BCC3*pow(logt,2))+(BCD3*pow(logt,3))+(BCE3*pow(logt,4))+(BCF3*pow(logt,5));
}
