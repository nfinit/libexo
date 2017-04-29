/* PWB UNIT CONVERSION DEFINITIONS
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file contains various unit conversion definitions to aid in
 * presenting computation output in human-readable format.
 *
 * Conversion order is presented left-to-right, meaning that "YR_DAY"
 * specifies the conversion of one year to days, while "DAY_HR" specifies
 * the conversion of one day to hours.
 */

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
#define M_MI 1609.344
#define M_AU 149597870700.0
