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

/* COMPLEX APPROXIMATIONS */

double star_luminosity_complex(double mass) {
  if (mass > 0.179f && mass <= 0.45f) {
    return pow(10, (2.028f*log(mass)-0.976f));
  }
  if (mass > 0.45f && mass <= 0.72f) {
    return pow(10, (4.572f*log(mass)-0.102f));
  }
  if (mass > 0.72f && mass <= 1.05f) {
    return pow(10, (5.743f*log(mass)-0.007f));
  }
  if (mass > 1.05f && mass <= 2.4f) {
    return pow(10, (4.329f*log(mass)+0.010f));
  }
  if (mass > 2.4f && mass <= 7.0f) {
    return pow(10, (3.967f*log(mass)+0.093f));
  }
  if (mass > 7.0f && mass <= 31.0f) {
    return pow(10, (2.865f*log(mass)+1.105f));
  }
}

/* EVOLUTIONARY MODELS */

double star_main_sequence_timeframe_start(double mass) {
  return 0.0805f/(pow(mass, 2.22f));
}

double star_main_sequence_timeframe_end(double mass) {
  return (10/pow(mass, 4.05f))*(0.0056f * pow((mass+3.993f), 3.16f) + 0.042f);
}

double star_luminosity_timeframe_start(double mass) {
  if (mass > 0.74f && mass < 1.5f) {
    return star_main_sequence_timeframe_end(mass)/2;
  }
  if (mass > 1.5f && mass < 10.0f) {
    return star_main_sequence_timeframe_end(mass)/2;
  }
}

double star_luminosity_timeframe_end(double mass) {
  if (mass > 0.74f && mass < 1.5f) {
    return 1.64f * pow(mass, 3.81f);
  }
  if (mass > 1.5f && mass < 10.0f) {
    return 2.22f * pow(mass, 3.77f);
  }
}

double star_effective_temperature_timeframe_start(double mass) {
  if (mass > 0.74f && mass < 1.5f) {
    return 1924.0f*pow(mass-0.7041f, 0.4f)+1628.0f * mass+2794.0f;
  }
  if (mass > 1.5f && mass < 10.0f) {
    return 13723.0f*pow(mass-0.12f, 0.4f)-8434.0f;
  }
}

double star_effective_temperature_timeframe_end(double mass) {
  if (mass > 0.74f && mass < 1.5f) {
    return -2709.0f*pow(mass+2.2635f, 1.5f)+9500.0f * mass+12304.0f;
  }
  if (mass > 1.5f && mass < 10.0f) {
    return -714.7f*pow(mass+0.4831f, 1.5f)-4504.0f*mass+2020.0f;
  }
}
