#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "all_your_base.h"

size_t rebase(int8_t* digits, int16_t input_base, int16_t output_base, size_t input_length) {
    if (!digits[0] || are_some_invalid_bases(input_base, output_base) || 
        contain_negatives(digits, input_length) || 
        contain_invalid_positive_digit(digits, input_length, input_base)) return 0;
    size_t len = 0;
    int8_t a_output_r[DIGITS_ARRAY_SIZE];
    int16_t i_input = sum_digits(digits, input_base, input_length);
    for(len = 0; i_input >= output_base; len++) {
        a_output_r[len] = i_input % output_base;
        i_input /= output_base;     
    }
    a_output_r[len] = i_input;
    int8_t* a_output = reverse_array(len, a_output_r);
    copy_array(a_output, digits, len + 1);
    return len + 1;
}

int8_t* reverse_array(size_t len, int8_t* a_output_r) {
    int8_t* a_output = malloc(len);;
    for(size_t index_a_output_r = 0; index_a_output_r <= len; index_a_output_r++)
        a_output[index_a_output_r] = a_output_r[len - index_a_output_r];
    return a_output;
}

int16_t sum_digits(int8_t* digits, int16_t input_base, size_t input_length) {
    int16_t i_input = 0;
    for (size_t index = 0; index < input_length; index++)
        i_input += digits[index] *pow(input_base, input_length - index - 1);
    return i_input;
}

bool are_some_invalid_bases(int16_t input_base, int16_t output_base) {
    return (input_base < 2 || output_base < 2);
}

bool contain_negatives(int8_t* digits, size_t input_length) {
    for (size_t index = 0; index < input_length; index++)
        if(digits[index] < 0) return true;
    return false;
}

bool contain_invalid_positive_digit(int8_t* digits, size_t input_length, int16_t input_base) {
    for (size_t index = 0; index < input_length; index++)
        if(digits[index] >= input_base) return true;
    return false;
}

