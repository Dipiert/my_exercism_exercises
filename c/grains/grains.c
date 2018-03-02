#include <stdint.h>
#include <math.h>
#include <stdio.h>

uint64_t square(int n_square) {
    return pow(2,n_square - 1);
}

uint64_t total() {
    return -1; //2^64 - 1, compare an unsigned and a signed value
}

