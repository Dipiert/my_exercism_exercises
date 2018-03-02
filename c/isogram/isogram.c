#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

bool is_isogram(const char* str) {
    uint8_t counter[26] = {0};
    for(;*str; str++)
        if(isalpha(*str) && ++counter[tolower(*str)-'a'] > 1)
            return false;
    return true;    
}

