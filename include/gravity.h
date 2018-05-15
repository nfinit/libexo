#ifndef _PWB_GRAVITY_H_
#define _PWB_GRAVITY_H_

/* PWB GRAVITY UTILITIES HEADER
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides function prototypes for the gravity
 * utilities file that can be used in other programs utilizing
 * these functions
 *
 * These functions work with the following units:
 * Surface gravity: meters/second^2
 * Length: meters
 * Mass: kilograms
 */

/*** surface gravity functions ***/
double surface_gravity(double mass, double radius);
double radius_sg(double mass, double sg);
double mass_sg(double radius, double sg);

#endif
