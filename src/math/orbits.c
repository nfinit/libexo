#include <math.h>
#include "orbits.h"

/* SMa to period~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Utilizes Kepler's third law to get the period of an
 * orbit from its semimajor axis using user-defined units
 */
double sma_to_period(double sma, enum orbital_units ou, enum time_units pu) {

	enum orbital_units orbit_unit;
	enum time_units period_unit;
	orbit_unit = AU;
	period_unit = years;

	double smaconv;
	double perconv;
	double smacb;
	double period;

	/* Convert input SMa to AU */
	smaconv = sma_conv(sma, ou, orbit_unit);

	/* Calculate orbital period (in years) */
	smacb = pow(fabs(smaconv),3);
	period = sqrt(smacb);

	/* Convert period to desired units */
	perconv = per_conv(period, period_unit, pu);

	return perconv;
}

/* Period to SMa~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Utilizes Kepler's third law to get the semimajor axis
 * of an orbit from its period using user-defined units
 */
double period_to_sma(double period, enum time_units pu, enum orbital_units ou) {

	enum orbital_units orbit_unit;
	enum time_units period_unit;
	orbit_unit = AU;
	period_unit = years;

	double smaconv;
	double perconv;
	double persq;
	double sma;

	/* Convert input period to years */
	perconv = per_conv(period, pu, period_unit);

	/* Calculate semimajor axis (in AU) */
	persq = pow(perconv,2);
	sma = pow(persq,(1.0/3.0));

	/* Convert semimajor axis to desired units */
	smaconv = sma_conv(sma, orbit_unit, ou);

	return smaconv;

}

/* SMa unit conversion function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Converts a semimajor axis between AU, kilometers or miles
 */
double sma_conv(double sma, enum orbital_units ou1, enum orbital_units ou2) {

	if (ou1 == AU) {
		if (ou2 == AU) {
			return sma;
		} else if (ou2 == km) {
			return sma*AU_KM;
		} else if (ou2 == mi) {
			return sma*AU_MI;
		}
	} else if (ou1 == km) {
		if (ou2 == AU) {
			return sma/AU_KM;
		} else if (ou2 == km) {
			return sma;
		} else if (ou2 == mi) {
			return (sma/AU_KM)*AU_MI;
		}
	} else if (ou1 == mi) {
		if (ou2 == AU) {
			return sma/AU_MI;
		} else if (ou2 == km) {
			return (sma/AU_MI)*AU_KM;
		} else if (ou2 == mi) {
			return sma;
		}
	}

	/* return 0 if an invalid unit was specified */
	return 0.0;

}

/* Period unit conversion function~~~~~~~~~~~~~~~~~~~~~~~~
 * Converts a period between years, days, hours or seconds
 */
double per_conv(double period, enum time_units pu1, enum time_units pu2) {

	if (pu1 == years) {
		if (pu2 == years) {
			return period;
		} else if (pu2 == days) {
			return period * YR_DAY;
		} else if (pu2 == hours) {
			return period * YR_DAY * DAY_HR;
		} else if (pu2 == minutes) {
			return period * YR_DAY * DAY_HR * HR_MIN;
		} else if (pu2 == seconds) {
			return period * YR_DAY * DAY_HR * HR_MIN * MIN_SEC;
		}
	} else if (pu1 == days) {
		if (pu2 == years) {
			return period/YR_DAY;
		} else if (pu2 == days) {
			return period;
		} else if (pu2 == hours) {
			return period * DAY_HR;
		} else if (pu2 == minutes) {
			return period * DAY_HR * HR_MIN;
		} else if (pu2 == seconds) {
			return period * DAY_HR * HR_MIN * MIN_SEC;
		}
	} else if (pu1 == hours) {
		if (pu2 == years) {
			return (period/DAY_HR)/YR_DAY;
		} else if (pu2 == days) {
			return period/DAY_HR;
		} else if (pu2 == hours) {
			return period;
		} else if (pu2 == minutes) {
			return period * HR_MIN;
		} else if (pu2 == seconds) {
			return period * MIN_SEC;
		}
	} else if (pu1 == minutes) {
		if (pu2 == years) {
			return ((period/HR_MIN)/DAY_HR)/YR_DAY;
		} else if (pu2 == days) {
			return (period/HR_MIN)/DAY_HR;
		} else if (pu2 == hours) {
			return period/HR_MIN;
		} else if (pu2 == minutes) {
			return period;
		} else if (pu2 == seconds) {
			return period * MIN_SEC;
		}
	} else if (pu1 == seconds) {
		if (pu2 == years) {
			return (((period/MIN_SEC)/HR_MIN)/DAY_HR)/YR_DAY;
		} else if (pu2 == days) {
			return ((period/MIN_SEC)/HR_MIN)/DAY_HR;
		} else if (pu2 == hours) {
			return (period/MIN_SEC)/HR_MIN;
		} else if (pu2 == minutes) {
			return period/MIN_SEC;
		} else if (pu2 == seconds) {
			return period;
		}
	}

	/* return 0 if an invalid unit was specified */
	return 0.0;

}
