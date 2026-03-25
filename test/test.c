/* LIBEXO TEST SUITE
* Libexo test suite for testing
*
* Revision I (25/26) (C) NFINIT Systems 2026
* Author:
*
* This file provides functions for testing different parts of libexo library
*/

#include "../include/test.h"
#include "../include/colour_print.h"
#include "../include/compat.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
    test_info test_info = {0, 0, 0};
    run_test_bool(false, true, &test_info);
    print_testing_info(test_info);
}

test_info run_test_double(double input_value, double expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %f, the input value: %f\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %f, the input value: %f\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}


test_info run_test_bool(bool input_value, bool expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %b, the input value: $b\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %b, the input value: %b\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

test_info run_test_int8(int8_p input_value, int8_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

test_info run_test_int16(int16_p input_value, int16_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

test_info run_test_int32(int32_p input_value, int32_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

test_info run_test_int64(int64_p input_value, int64_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}


test_info run_test_uint8(uint8_p input_value, uint8_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

test_info run_test_uint16(uint16_p input_value, uint16_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

test_info run_test_uint32(uint32_p input_value, uint32_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

test_info run_test_uint64(uint64_p input_value, uint64_p expected_value, test_info *test_info) {
    test_info->n_of_tests += 1;
    if (input_value == expected_value) {
        print_test_result(true);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_succ_tests += 1;
    }
    else {
        print_test_result(false);
        printf(" Expected value: %i, the input value: %i\n", expected_value, input_value);
        test_info->n_of_failed_tests += 1;
    }
    return *test_info;
}

void print_testing_info(test_info test_info) {
    printf("Testing complete. Run: %i ", test_info.n_of_tests);
    print_col_text(MAGENTA, "tests in total, ");
    printf("%i ", test_info.n_of_succ_tests);
    print_col_text(GREEN, "successful tests, ");
    printf("%i ", test_info.n_of_failed_tests);
    print_col_text(RED, "failed tests");
    printf(".\n");
}

void print_test_result(bool result) {
    if (result) {
        printf("[");
        print_col_text(GREEN, "OK");
        printf("]");
    } else {
        printf("[");
        print_col_text(RED, "FAIL");
        printf("]");
    }
}
