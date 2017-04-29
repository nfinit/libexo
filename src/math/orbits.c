/* PWB ORBITAL UTILITIES
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides functions for basic orbital characterization, including
 * determining orbital period, semimajor axis and combined host-satellite mass
 * using Kepler's third law
 *
 * This program performs calculations on the following units:
 * Semimajor axis: meters
 * Orbital period: seconds
 * Mass: kilograms
 */

#include <math.h>
#include "../headers/constants.h"

/* SEMIMAJOR AXIS+COMBINED MASS TO ORBITAL PERIOD:
 * Converts an orbit's semimajor axis (in meters) to an
 * orbital period (in seconds), factoring in the combined
 * mass of both host and satellite
 */
double period(double sma, double hostmass, double satmass) 
{
	/* declare variables */
	double t;
	double m;
	double t_numerator;
	double t_denominator;

	/* initialize combined mass */
	m = fabs(hostmass + satmass);

	/* compute orbital period */
	t_numerator = 4.0 * pow(M_PI, 2.0) * pow(fabs(sma), 3.0);
	t_denominator = CONST_G * m;
	t = sqrt(t_numerator / t_denominator);

	/* return period (in seconds) */
	return t;
}

/* ORBITAL PERIOD+COMBINED MASS TO SEMIMAJOR AXIS:
 * Converts an orbit's period (in seconds) to a
 * semimajor axis (in meters), factoring in the combined
 * mass of both host and satellite
 */
double sma(double period, double hostmass, double satmass) 
{
	/* declare variables */
	double r;
	double m;
	double r_numerator;
	double r_denominator;

	/* initialize combined mass */
	m = fabs(hostmass + satmass);

	/* compute semimajor axis */
	r_numerator = CONST_G * m * pow(fabs(period), 2.0);
	r_denominator = 4 * pow(M_PI, 2.0);
	r = pow(r_numerator / r_denominator, 1.0 / 3.0);

	/* return semimajor axis (in meters) */
	return r;
}

/* SEMIMAJOR AXIS+ORBITAL PERIOD TO COMBINED MASS:
 * Uses the semimajor axis and period of an orbit
 * to approximate the combined mass of the two objects
 */
double mass(double period, double sma)
{
	/* declare variables */
	double m;
	double m_numerator;
	double m_denominator;

	/* compute combined mass */
	m_numerator = 4 * pow(M_PI, 2.0) * pow(fabs(sma),3);
	m_denominator = CONST_G * pow(fabs(period),2);
	m = m_numerator / m_denominator;

	/* return combined mass (in kilograms) */
	return m;
}
