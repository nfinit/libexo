/* PWB UNIT CONVERSION DEFINITION ARRAYS
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file contains definitions for supported units in string form,
 * for parsing functions
 */

/* UNIT STRING ARRAYS */
char *sma_units[] = {"AU", "KM", "M", "au", "km", "m"};
char *per_units[] = {"years", "days", "hours", "minutes", "seconds"};

/* UNIT ARRAY LENGTHS */
#define NUM_SMA_UNITS 3
#define NUM_PER_UNITS 5

/* UNIT CONVERSION TABLES */
double sma_table[NUM_SMA_UNITS][NUM_SMA_UNITS] = {
	{1.0, 149597870.7, 149597870700.0},
	{6.6845871222684455E-9, 1.0, 1000},
	{6.68458712226845E-12, 0.001, 1.0}
};
double per_table[NUM_PER_UNITS][NUM_PER_UNITS] = {
	{1.0, 365.0, 8760.0, 525600.0, 31536000.0},
	{0.0027397260, 1.0, 24.0, 1440.0, 86400.0},
	{1.1415525E-4, 0.04167, 1.0, 60.0, 3600.0},
	{1.90259E-6, 6.9444E-4, 0.0167, 1.0, 60.0},
	{3.17097E-8, 1.15741E-5, 2.78E-4, 0.0167, 1.0}
};
