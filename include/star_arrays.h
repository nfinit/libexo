#ifndef _EXO_ARRAY_STARS_H_
#define _EXO_ARRAY_STARS_H_

/* LIBEXO STELLAR UTILITY ARRAYS
 *
 * Revision I (01/18) (C) NFINIT Systems 2018
 * Author: ict (ict@nfinit.systems)
 *
 * This file contains defines various spectral types and other
 * general properties of stars
 */

/* SPECTRAL TYPE TEMPERATURE BOUNDARIES
 * An array of boundaries corresponding to the minimum temperatures of
 * each spectral type that can be indexed by the spectype_T enumeration
 * Notes:
 * * Minimum temperature for O-type stars is defined as 33,000 kelvin
 *   based on the observed temperatures of O9.7 V stars
 */
double SPECTRAL_TEMP[] = {33000,10000,7500,6000,5200,3700,2400,1300,550,0,-1};

/* some considerations for classifying O-type stars */
#define EARLY_O 2 /* No stars of class O1 or O0 have been observed */
#define MAX_STAR_TEMP 52000 /* BI 253 (O2 V) has a temperature of 50,100 K */

/* MK TYPE STRINGS */
char* SPECTRAL_STR[] = {"O","B","A","F","G","K","M","L","T","Y","NO TYPE"};

/* SPECTRAL TYPE MASS BOUNDARIES
 * An array of boundaries corresponding to the minimum masses of each
 * spectral type that can be indexed by the spectype_T enumeration
 * As a star's mass is not really a reliable way of determining its type,
 * this array serves more as a way of roughly but somewhat plausibly
 * filling in "blanks" on generated or poorly characterized objects
 * whose masses are unknown but have otherwise been assigned classification.
 */

 /*TODO: Create mass boundary array*/

#endif
