#ifndef _PWB_ARRAY_UNITS_H_
#define _PWB_ARRAY_UNITS_H_

/* PWB UNIT CONVERSION DEFINITION ARRAYS
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file contains definitions for supported units in string form,
 * for parsing functions
 */

/* UNIT ARRAY LENGTHS */
#define NUM_SMA_UNITS  3
#define NUM_PER_UNITS  5
#define NUM_MASS_UNITS 4
#define NUM_TEMP_UNITS 3

/* UNIT STRING ARRAYS */
char *sma_units[] = {"AU", "km", "m",
                     "au", "KM", "M"};
char *per_units[] = {"years", "days", "hours", "minutes", "seconds",
		     "year", "day", "hour", "minute", "second",
                     "yr", "d", "hr", "min", "sec"};
char *mass_units[] = {"kg", "Me", "Mj", "MSun", 
                      "KG", "ME", "MJ", "MSUN",
		      "Kg", "me", "mj", "msun"};
char *temp_units[] = {"K", "C", "F",
		      "k", "c", "f"};

/* Semimajor axis unit conversion table */
double sma_table[NUM_SMA_UNITS][NUM_SMA_UNITS] = {
	{1.0, 149597870.7, 149597870700.0},
	{6.6845871222684455E-9, 1.0, 1000},
	{6.68458712226845E-12, 0.001, 1.0}
};

/* Period unit conversion table */
double per_table[NUM_PER_UNITS][NUM_PER_UNITS] = {
	{1.0, 365.0, 8760.0, 525600.0, 31536000.0},
	{0.0027397260, 1.0, 24.0, 1440.0, 86400.0},
	{1.1415525E-4, 0.04167, 1.0, 60.0, 3600.0},
	{1.90259E-6, 6.9444E-4, 0.0167, 1.0, 60.0},
	{3.17097E-8, 1.15741E-5, 2.78E-4, 0.0167, 1.0}
};

/* Mass unit conversion table */
double mass_table[NUM_MASS_UNITS][NUM_MASS_UNITS] = {
	{1.0, 1.6744252E-25, 5.26834E-28, 5.029081E-31},
	{5.9721986E+24, 1.000, 0.00314636, 3.003467E-6},
	{1.89813E+27, 317.828, 1.0000000000, 9.5458E-4},
	{1.988435E+30, 332948.6, 1047.58, 1.0000000000}
};

#endif
