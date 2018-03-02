#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "nth_prime.h"

uint32_t nth(uint32_t n) {
    if (!n) return n;
    bool founded = false, prime = true;
    uint32_t cant_primes = 0, fast_index = 2, slow_index;   
    while(!founded) {
        for(slow_index = 2; slow_index < fast_index; slow_index++)
            if (fast_index % slow_index == 0) prime = false;        
        if (prime) cant_primes++;
        if (cant_primes == n) founded = true;   
        else {
            prime = true;
            fast_index++;   
        }
    }   
    return fast_index;
}

