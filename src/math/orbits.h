/* Unit enumeration */

enum orbital_units
{
	AU,
	km,
	mi
};

enum time_units
{
	seconds,
	minutes,
	hours,
	days,
	years
};

/* Unit equivalences */

#define AU_KM 149600000.0
#define AU_MI 92960000.0

#define YR_DAY 365.0
#define DAY_HR 24.0
#define HR_MIN 60.0
#define MIN_SEC 60.0

/* Function prototypes */

double sma_to_period(double sma, enum orbital_units ou, enum time_units pu);
double period_to_sma(double period, enum time_units pu, enum orbital_units ou);
double sma_conv(double sma, enum orbital_units ou1, enum orbital_units ou2);
double per_conv(double period, enum time_units pu1, enum orbital_units pu2);
