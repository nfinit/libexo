/* LIBEXO STELLAR UTILITIES
 *
 * Revision I (08/19) (C) NFINIT Systems 2019
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides mathematical routines for characterizing stars.
 * 
 * Some procedures derived from methods prseented by Phillip J. Flower
 * in "Transformations from Theoretical Hertsprung-Russell Diagrams:
 * Effective Temperatures, B-V Colors, and Bolometric Corrections" (1996)
 * with corrected coefficients provided by Guillermo Torres in "On the
 * use of Empirical Bolometric Corrections for Stars" (2010) 
 */

#include <math.h>
#include <stdbool.h>
#include "../include/stars.h"

/* Procedure for deriving a bolometric correction given stellar effective
 * temperature based on Phillip J. Flower's method 
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

/* Procedure for computing B-V color index for main sequence,
 * subgiant and giant stars based on Phillip J. Flower's method
 */
double bv(double temperature, temp_T unit)
{
	/* Declare starting variables */
	double t,logt;
	/* Convert input temperature to Kelvin */
	t = convert_temp(temperature,unit,KELVIN);
	/* Check supplied arguments */
	if (t < 0 || unit == NO_TEMP_UNIT) return 0;
	/* Begin computation */
	logt = log10(t);
	return VA+(VB*logt)+(VC*pow(logt,2))+(VD*pow(logt,3))+(VE*pow(logt,4))+(VF*pow(logt,5))+(VG*pow(logt,6))+(VH*pow(logt,7));
}

/* Procedure for computing B-V color index for supergiant stars
 * based on Phillip J. Flower's method
 */
double bv_I(double temperature, temp_T unit)
{
	/* Declare starting variables */
	double t,logt;
	/* Convert input temperature to Kelvin */
	t = convert_temp(temperature,unit,KELVIN);
	/* Check supplied arguments */
	if (t < 0 || unit == NO_TEMP_UNIT) return 0;
	/* Begin computation */
	logt = log10(t);
	return SA+(SB*logt)+(SC*pow(logt,2))+(SD*pow(logt,3))+(SE*pow(logt,4))+(SF*pow(logt,5));
}

/* SIMPLE APPROXIMATIONS */

double star_effective_termperature_simple(double mass) {
  return 5778.0f * pow(mass, 0.54);
}

double star_luminosity_simple(double mass) {
  if (mass > 0.08f && mass < 0.43f) {
    return 0.23f * pow(mass, 2.3f);
  }
  if (mass > 0.43f && mass < 2.0f) {
    return pow(mass, 4.0f);
  }
  if (mass > 2.0f && mass < 55.0f) {
    return 1.4f * pow(mass, 3.5f);
  }
  if (mass > 55.0f) {
    return 32000 * mass;
  }
}

double star_radius_simple(double luminosity, double temperature) {
  return sqrt(luminosity)/(pow(temperature/5778.0f, 2));
}

double star_lifetime_simple(double mass, double luminosity) {
  return (10.9f * mass)/luminosity;
}
