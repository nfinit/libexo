#ifndef _PWB_STARS_H_
#define _PWB_STARS_H_

/* PWB STELLAR UTILITY DEFINITIONS 
 *
 * Revision I (01/18) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file contains prototypes and definitions for various functions to
 * assist with characterizing stars.
 */

#include "units.h"

/* number of supported spectral types */
#define NUM_SPECTRAL_TYPES 9

/* CLASSIFICATION
 * Enumerations to define spectral types and luminosity classes
 */
typedef enum spectral_type {O,B,A,F,G,K,M,L,T,Y,NO_TYPE} spectype_T;
typedef enum luminosity_class {Ia,Ib,II,III,IV,V,VI,NO_CLASS} lumclass_T;
/* Spectral class structure */
typedef struct {
	spectype_T spectral_type;
	int sub_type;
	lumclass_T luminosity_class;
	char *peculiarities;
} spec_T;

/* STELLAR REPRESENTATION
 * The following data structure represents the qualities of a star most
 * relevant to the calculations performed in the Workbench tools.
 * UNITS***************************************************************
 * Mass: 		kilograms
 * Temperature:		kelvin
 * Radius:		kilometers
 * Age:			gigayears
 * Rotation period:	seconds
 */
typedef struct {
	spec_T spectral_class;
	double temperature;
	double mass;
	double radius;
	double age;
	double rotation_period;
} star_T;

/*** prototypes for spectral classification ***/
spectype_T infer_type(double temperature, temp_T unit);
int infer_subtype(double temperature, temp_T unit, spectype_T type);
spectype_T infer_type_bv(double bv);
char *spectype_T_string(spectype_T t);
/*** prototypes for standardized property extraction ***/
double get_mass(star_T *star, mass_T unit);
double get_temp(star_T *star, temp_T unit);

#endif
