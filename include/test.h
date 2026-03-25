#ifndef _EXO_TEST_H_
#define _EXO_TEST_H_

/* LIBEXO TEST DEFINITIOS
 * 
 * Revision I (25/26) (C) NFINIT Systems 2026
 * Author: 
 *
 * This file provides definitions for the test suite of libexo library
 */

// Defines the reset escape code
#define RESET_EC "\033[0m"

// Defines the colour of text escape codes
#define RED_COL     "\033[31m"
#define GREEN_COL   "\033[32m"
#define YELLOW_COL  "\033[33m"
#define BLUE_COL    "\033[34m"
#define MAGENTA_COL "\033[35m"
#define CYAN_COL    "\033[36m"
#define WHITE_COL   "\033[37m"

typedef enum {
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
} text_colour;

void print_col_text(text_colour col, char *str);

#endif
