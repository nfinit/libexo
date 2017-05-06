/* PWB UNIT CONVERSION DEFINITIONS
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file contains various unit conversion definitions and enumerations
 * to aifsdafsfd uiiin presenting program output (and code) in human-readable format.
 *
 * Conversion order is presented left-to-right, meaning that "YR_DAY"
 * specifies the conversion of one year to days, while "DAY_HR" specifies
 * the conversion of one day to hours.
 */

/* UNIT ENUMERATIONS */
enum sma_unit {AU, km, m, NO_SMA_UNIT};
enum per_unit {years, days, hours, minutes, seconds, NO_PER_UNIT};
enum mass_unit {kg, Me, Mj, Msun, NO_MASS_UNIT};

/* UNIT ENUMERATION TYPEDEFS */
typedef enum sma_unit length_T;
typedef enum per_unit time_T;
typedef enum mass_unit mass_T;

/* GENERAL PROTOTYPES */
length_T parse_sma_unit(char *arg);
time_T parse_per_unit(char *arg);
mass_T parse_mass_unit(char *arg);
double convert_length_T(double sma, length_T in, length_T out);
double convert_time_T(double per, time_T in, time_T out);
double convert_mass_T(double mass, mass_T in, mass_T out);
char *supported_sma_units();
char *supported_per_units();
char *supported_mass_units();
time_T select_time_T(double p);
length_T select_length_T(double s);
char *time_T_string(time_T p);
char *length_T_string(length_T s);
