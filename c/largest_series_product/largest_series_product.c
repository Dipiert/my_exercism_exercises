#include "largest_series_product.h"
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>

unsigned long largest_series_product(char* str, size_t n_digits) {
    unsigned long sum = 1;
    unsigned long largest = 0, spans = 0, spans_with_zero = 0;
    if (is_span_longer_than_str_length(str, n_digits) || !are_valid_chars(str)) return -1;
    if (is_no_digits(n_digits)) return 1;
    for(size_t i = 0; i <= strlen(str) - n_digits; i++) {
        for(size_t j = i; j < i + n_digits; j++) {
            spans++;
            if(str[j] - '0' == 0) spans_with_zero++;
            sum *= (int) (str[j] - '0');
        }
        if (sum >= largest) largest = sum;
        sum = 1;
    }
    if(spans == spans_with_zero) return 0;
    return largest;
}

bool is_span_longer_than_str_length(char* str, size_t n_digits) {
    return (n_digits > strlen(str));
}

bool is_no_digits(size_t n_digits) {
    return (n_digits == 0);
}

bool are_valid_chars(char* input) {
    while (*input) if(!isdigit(*input++)) return false;
    return true;
}

