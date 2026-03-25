#ifndef _EXO_TEST_H_
#define _EXO_TEST_H_

/* LIBEXO TEST DEFINITIOS
 * 
 * Revision I (25/26) (C) NFINIT Systems 2026
 * Author: 
 *
 * This file provides definitions for the test suite of libexo library
 */

#include "compat.h"
#include <stdbool.h>

typedef struct test_info {
    uint16_p n_of_tests;
    uint16_p n_of_succ_tests;
    uint16_p n_of_failed_tests;
} test_info;

void print_test_result(bool result);

// Tests for floats

test_info run_test_double(double input_value, double expected_value, test_info *test_info);

// Tests for bools

test_info run_test_bool(bool input_value, bool expected_value, test_info *test_info);

// Tests for signed integers

test_info run_test_int8(int8_p input_value, int8_p expected_value, test_info *test_info);
test_info run_test_int16(int16_p input_value, int16_p expected_value, test_info *test_info);
test_info run_test_int32(int32_p input_value, int32_p expected_value, test_info *test_info);
test_info run_test_int64(int64_p input_value, int64_p expected_value, test_info *test_info);

// Tests for unsigned integers

test_info run_test_uint8(uint8_p input_value, uint8_p expected_value, test_info *test_info);
test_info run_test_uint16(uint16_p input_value, uint16_p expected_value, test_info *test_info);
test_info run_test_uint32(uint32_p input_value, uint32_p expected_value, test_info *test_info);
test_info run_test_uint64(uint64_p input_value, uint64_p expected_value, test_info *test_info);

// Printing the overall test information

void print_testing_info(test_info test_info);

#endif
