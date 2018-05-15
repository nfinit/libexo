#ifndef _PWB_ORBITS_H_
#define _PWB_ORBITS_H_

/* PWB ORBITAL UTILITIES HEADER
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides function prototypes for the main orbital
 * utilities file that can be used in other programs utilizing
 * these functions
 *
 * These functions work with the following units:
 * Orbital periods: seconds
 * Semimajor axes: meters
 * Masses: kilograms
 *
 */

double period(double sma, double hostmass, double satmass);
double sma(double period, double hostmass, double satmass);
double mass(double sma, double period);
double perihelion(double sma, double e);
double aphelion(double sma, double e);

#endif
