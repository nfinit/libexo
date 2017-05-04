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
enum sma_unit {AU, km, mi, m, ft, NO_SMA_UNIT};
enum per_unit {years, days, hours, minutes, seconds, NO_PER_UNIT};
enum mass_unit {kg, Me, Mj, Msun, NO_MASS_UNIT};

/* UNIT ENUMERATION TYPEDEFS */
typedef enum sma_unit smaunit;
typedef enum per_unit perunit;
typedef enum mass_unit massunit;

/* BASIC TIME CONVERSION */
#define YR_DAY 365.0
#define DAY_HR 24.0
#define HR_MIN 60.0
#define MIN_SEC 60.0
#define SEC_MSEC 1000.0

/* EXT. TIME CONVERSION (YEARS) */
#define YR_HR YR_DAY * DAY_HR
#define YR_MIN YR_HR * HR_MIN
#define YR_SEC YR_MIN * MIN_SEC
#define YR_MSEC YR_SEC * SEC_MSEC

/* EXT. TIME CONVERSION (DAYS) */
#define DAY_MIN DAY_HR * HR_MIN
#define DAY_SEC DAY_MIN * MIN_SEC
#define DAY_MSEC DAY_SEC * SEC_MSEC

/* EXT. TIME CONVERSION (HOURS) */
#define HR_SEC HR_MIN * MIN_SEC
#define HR_MSEC HR_SEC * SEC_MSEC

/* DISTANCE CONVERSION */
#define AU_M 149597870700.0
#define KM_M 1000.0
#define MI_KM 1.60934
#define MI_M 1609.344
#define MI_FT 5280.0
#define M_FT 3.28084

/* EXT. DISTANCE CONVERSION (AU) */

#define AU_FT AU_M * M_FT
#define AU_KM AU_M / KM_M
#define AU_MI AU_KM / MI_KM

/* EXT. DISTANCE CONVERSION (KM) */

#define KM_FT KM_M * M_FT

/* EXT. DISTANCE CONVERSION (M) */
#define M_MI M_FT / MI_FT

/* EXT. DISTANCE CONVERSION (FT) */
#define FT_KM M_FT / KM_M
#define FT_AU M_FT / AU_M

/* GENERAL PROTOTYPES */
smaunit parse_sma_unit(char *arg);
perunit parse_per_unit(char *arg);
double convert_smaunit(double sma, smaunit in, smaunit out);
double convert_perunit(double per, perunit in, perunit out);
