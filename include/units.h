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
typedef enum sma_unit smaunit;
typedef enum per_unit perunit;
typedef enum mass_unit massunit;

/* GENERAL PROTOTYPES */
smaunit parse_sma_unit(char *arg);
perunit parse_per_unit(char *arg);
massunit parse_mass_unit(char *arg);
double convert_smaunit(double sma, smaunit in, smaunit out);
double convert_perunit(double per, perunit in, perunit out);
double convert_massunit(double mass, massunit in, massunit out);
