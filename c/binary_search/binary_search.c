#include "binary_search.h"

size_t left_index, right_index;

int* binary_search(int num, int* arr, size_t length) {
    if (!arr || is_missing(num, arr, length)) return 0;
    left_index = 0;
    right_index = length - 1;
    size_t middle = (left_index + right_index) / 2;
    while (left_index <= right_index) {
        if(arr[middle] == num) return &arr[middle];
        else if (num < arr[middle]) right_index = middle - 1;       
        else left_index = middle + 1;       
        middle = (left_index + right_index) / 2;        
    }
    return 0;
}

bool is_missing(int num, int* arr, size_t length) {
    for (size_t index = 0; index < length; index++)
        if (arr[index] == num) return false;    
    return true;
}

