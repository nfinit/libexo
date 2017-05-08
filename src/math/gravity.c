/* PWB GRAVITY UTILITIES
 *
 * Revision I (05/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides functions for functions relating to an object's
 * gravitational characteristics, such as surface gravity and hill sphere
 * radius.
 *
 * This program performs calculations on the following units:
 * Surface gravity: meters/second^2
 * Length: meters
 * Mass: kilograms
 */

#include <math.h>
#include "../../include/constants.h"

/* SURFACE GRAVITY FROM MASS+RADIUS:
 * Derives the surface gravity in meters per second squared of an 
 * object from its mass and radius in kilograms and meters, respectively.
 */
double surface_gravity(double mass, double radius) 
{
	return CONST_G * mass / (radius * radius);
}

/* RADIUS FROM SURFACE GRAVITY+MASS:
 * Derives the radius of an object in meters from its
 * mass and surface gravity in kilograms and meters per second
 * squared, respectively.
 */
double radius_sg(double mass, double sg)
{
	return pow(CONST_G * mass / sg, 1.0 / 2.0);	 
}

/* MASS FROM SURFACE GRAVITY+RADIUS:
 * Derives the mass of an object in kilograms from its
 * radius and surface gravity in meters and meters per second
 * squared, respectively.
 */
double mass_sg(double radius, double sg)
{
	return sg * (radius * radius) / CONST_G;
}
