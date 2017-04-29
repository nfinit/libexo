/* PWB GENERAL UTILITIES
 * Unit parsing and conversion
 *
 * Revision I (04/17) (C) NFINIT Systems 2017
 * Author: ict (ict@nfinit.systems)
 *
 * This file provides functions for parsing and conversion of
 * supported units
 */

#include <string.h>
#include "../headers/units.h"
#include "../headers/unit_arrays.h"

/* Parse a string to an SmA unit
 */
smaunit parse_sma_unit(char *arg)
{
	/* declare variables */
	int i;
	smaunit r;

	/* iterate through SMA unit array */
	for (i = 0; i < NUM_SMA_UNITS; i++)
	{
		if (strcmp(arg, smau[i]) == 0) {
			r = i;
			break;
		} else if (strcmp(arg, smau[i+NUM_SMA_UNITS]) == 0) {
			r = i;
			break;
		} else {
			r = NO_SMA_UNIT;
		}
		
	}

	/* return result */
	return r;

}

/* Parse a string to a period unit
 */
perunit parse_per_unit(char *arg)
{
	/* declare variables */
	int i;
	perunit r;

	/* iterate through period unit array */
	for (i = 0; i < NUM_PER_UNITS; i++)
	{
		if (strcmp(arg, peru[i]) == 0) {
			r = i;
			break;
		} else {
			r = NO_PER_UNIT;
		}
	}

	/* return result */
	return r;
}

double convert_smaunit(double sma, smaunit in, smaunit out)
{
	switch (in) {
		case AU:
			switch (out) {
				case AU:
					return sma;
				case km:
					return sma * AU_KM;
				case mi:
					return sma * AU_MI;
				case m:
					return sma * AU_M;
				case ft:
					return sma * AU_FT;
			}
		case km:
			switch (out) {
				case AU:
					return sma / AU_KM;
				case km:
					return sma;
				case mi:
					return sma / MI_KM;
				case m:
					return sma * KM_M;
				case ft:
					return sma * KM_FT;
			}
		case mi:
			switch (out) {
				case AU:
					return sma / AU_MI;
				case km:
					return sma * MI_KM;
				case mi:
					return sma;
				case m:
					return sma * MI_M;
				case ft:
					return sma * MI_FT;
			}
		case m:
			switch (out) {
				case AU:
					return sma / AU_M;
				case km:
					return sma / KM_M;
				case mi:
					return sma * M_MI;
				case m:
					return sma;
				case ft:
					return sma * M_FT;
			}
		case ft:
			switch (out) {
				case AU:
					return sma * FT_AU;
				case km:
					return (sma / M_FT) / KM_M;
				case mi:
					return sma / MI_FT;
				case m:
					return sma / M_FT;
				case ft:
					return sma;
			}
	}	
}

double convert_perunit(double per, perunit in, perunit out)
{
	return 0.0;
}
