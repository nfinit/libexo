#ifndef _EXO_STARS_H_
#define _EXO_STARS_H_

/* LIBEXO STELLAR UTILITY DEFINITIONS 
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

/* bolometric correction coefficients for log Teff < 3.70 */
#define BCA1 -0.190537291496456E+05
#define BCB1  0.155144866764412E+05
#define BCC1 -0.421278819301717E+04
#define BCD1  0.381476328422343E+03

/* bolometric correction coefficients for log Teff < 3.90 */
#define BCA2 -0.370510203809015E+05
#define BCB2  0.385672629965804E+05
#define BCC2 -0.150651486316025E+05
#define BCD2  0.261724637119416E+04
#define BCE2 -0.170623810323864E+03

/* bolometric correction coefficients for log Teff > 3.90 */
#define BCA3 -0.118115450538963E+06
#define BCB3  0.137145973583929E+06
#define BCC3 -0.636233812100225E+05
#define BCD3  0.147412923562646E+05
#define BCE3 -0.170587278406872E+04
#define BCF3  0.788731721804990E+02

/* effective temperature function coefficients for typical stars */
#define VA    3.979145106714099
#define VB   -0.654992268598245
#define VC    1.740690042385095
#define VD   -4.608815154057166
#define VE    6.792599779944473
#define VF   -5.396909891322525
#define VG    2.192970376522490
#define VH   -0.359495739295671

/* effective temperature function coefficients for supergiants */
#define SA    4.012559732366214
#define SB   -1.055043117465989
#define SC    2.133394538571825
#define SD   -2.459769794654992
#define SE    1.349423943497744
#define SF   -0.283942579112032

/*** prototypes for spectral classification ***/
spectype_T infer_type(double temperature, temp_T unit);
int infer_subtype(double temperature, temp_T unit, spectype_T type);
spectype_T infer_type_bv(double bv);
char *spectype_T_string(spectype_T t);
/*** prototypes for standardized property extraction ***/
double get_mass(star_T *star, mass_T unit);
double get_temp(star_T *star, temp_T unit);
/*** prototypes for mathematical procedures ***/
double bcv(double temperature, temp_T unit);
double bv(double temperature, temp_T unit);
double bv_I(double temperature, temp_T unit);

#endif
