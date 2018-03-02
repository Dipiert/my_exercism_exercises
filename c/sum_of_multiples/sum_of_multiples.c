#include "sum_of_multiples.h"

long sum_of_multiples(const unsigned int* multiples, size_t num_elements, size_t n) {
    if(multiples == NULL) return 0;
    long sum = 0;
    for(size_t index = 1; index < n; index++)
        if( is_multiple(multiples, num_elements, index))
            sum += index;   
    return sum;
}

bool is_multiple(const unsigned int* multiples, size_t num_elements, const unsigned int num) {
    for (size_t index = 0; index < num_elements; index++)
        if (multiples[index] != 0 && num % multiples[index] == 0) return true;
    return false;
}

