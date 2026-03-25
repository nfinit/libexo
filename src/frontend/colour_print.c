/* LIBEXO COLOUR TERMINAL OUTPUT
* Libexo test suite for testing
*
* Revision I (25/26) (C) NFINIT Systems 2026
* Author:
*
* This files provides functions for printing coloured text output in the terminal
*/

#include "../../include/colour_print.h"
#include "../../include/compat.h"
#include <stdio.h>

void print_col_text(text_colour col, char *str) {
    switch (col) {
        case RED: printf( "%s%s%s", RED_COL, str, RESET_EC);
            break;
        case GREEN: printf( "%s%s%s",GREEN_COL, str, RESET_EC);
            break;
        case YELLOW: printf( "%s%s%s",YELLOW_COL, str, RESET_EC);
            break;
        case BLUE: printf( "%s%s%s",BLUE_COL, str, RESET_EC);
            break;
        case MAGENTA: printf( "%s%s%s",MAGENTA_COL, str, RESET_EC);
           break;
        case CYAN: printf( "%s%s%s",CYAN_COL, str, RESET_EC);
            break;
        case WHITE: printf( "%s%s%s",WHITE_COL, str, RESET_EC);
            break;
    }
}

void print_col_text_nd(text_colour col, char *str) {
    switch (col) {
        case RED: printf( "%s%s%s\n", RED_COL, str, RESET_EC);
            break;
        case GREEN: printf( "%s%s%s\n",GREEN_COL, str, RESET_EC);
            break;
        case YELLOW: printf( "%s%s%s\n",YELLOW_COL, str, RESET_EC);
            break;
        case BLUE: printf( "%s%s%s\n",BLUE_COL, str, RESET_EC);
            break;
        case MAGENTA: printf( "%s%s%s\n",MAGENTA_COL, str, RESET_EC);
           break;
        case CYAN: printf( "%s%s%s\n",CYAN_COL, str, RESET_EC);
            break;
        case WHITE: printf( "%s%s%s\n",WHITE_COL, str, RESET_EC);
            break;
    }
}
