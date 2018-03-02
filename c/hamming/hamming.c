#include "hamming.h"

int compute(char* str1, char* str2) {
    size_t dist = 0;
    if (str1 == NULL || str2 == NULL) return -1;    
    size_t len_str1 = strlen(str1);
    if (len_str1 != strlen(str2)) return -1;
    for(size_t i = 0; i < len_str1; i++)
        if (str1[i] != str2[i]) dist++;
    return dist;    
}

