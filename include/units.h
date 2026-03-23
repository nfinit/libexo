#ifndef _EXO_UNITS_H_
#define _EXO_UNITS_H_

/* LIBEXO UNIT CONVERSION DEFINITIONS
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file contains various unit conversion definitions and enumerations
 * for presenting program output (and code) in human-readable format.
 */

/* UNIT ENUMERATIONS */
enum length_unit {AU, km, m, NO_SMA_UNIT};
enum time_unit {years, days, hours, minutes, seconds, NO_PER_UNIT};
enum mass_unit {kg, Me, Mj, Msun, NO_MASS_UNIT};
enum temp_unit {KELVIN, CELSIUS, FAHRENHEIT, NO_TEMP_UNIT};

/* UNIT ENUMERATION TYPEDEFS */
typedef enum length_unit length_T;
typedef enum time_unit time_T;
typedef enum mass_unit mass_T;
typedef enum temp_unit temp_T;

/* GENERAL PROTOTYPES */
length_T parse_sma_unit(char *arg);
time_T parse_per_unit(char *arg);
mass_T parse_mass_unit(char *arg);
temp_T parse_temp_unit(char *arg);
double convert_length(double sma, length_T in, length_T out);
double convert_time(double per, time_T in, time_T out);
double convert_mass(double mass, mass_T in, mass_T out);
double convert_temp(double temp, temp_T in, temp_T out);
char *supported_sma_units();
char *supported_per_units();
char *supported_mass_units();
char *supported_temp_units();
time_T select_time_T(double p);
length_T select_length_T(double s);
char *time_T_string(time_T p);
char *length_T_string(length_T s);

#endif
