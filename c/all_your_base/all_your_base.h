#ifndef ALL_YOUR_BASE_H

#define ALL_YOUR_BASE_H
#define DIGITS_ARRAY_SIZE 64

#include <stdbool.h>

size_t rebase(int8_t* digits, int16_t input_base, int16_t output_base, size_t input_length);
void copy_array(int8_t src[], int8_t dest[DIGITS_ARRAY_SIZE], size_t n);
bool contain_negatives(int8_t* digits, size_t input_length);
bool contain_invalid_positive_digit(int8_t* digits, size_t input_length, int16_t input_base);
bool are_some_invalid_bases(int16_t input_base, int16_t output_base);
int16_t sum_digits(int8_t* digits, int16_t input_base, size_t input_length);
int8_t* reverse_array(size_t len, int8_t* a_output_r);
#endif

