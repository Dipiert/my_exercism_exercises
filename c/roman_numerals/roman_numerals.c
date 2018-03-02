#include "roman_numerals.h"

struct Numeral {
    char* symbol;
    short value; 
};
struct Numeral numerals[SYMBOLS_LENGTH];

char * to_roman_numeral(int number) {   
    char * result = calloc(1, BUFFER_LENGTH);
    initialize_numerals();
    for (size_t index = 0; index < SYMBOLS_LENGTH; index++){
        if (number >= numerals[index].value) {
            short cant_symbol = number / numerals[index].value;
            for (short i = 0; i < cant_symbol; i++)
                strcat(result, numerals[index].symbol);
            number -= numerals[index].value * cant_symbol;
            index = 0;
        }
    }
    return result;
}

void initialize_numerals() {
static char * symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
static const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (size_t index = 0; index < SYMBOLS_LENGTH; index++) {
        numerals[index].symbol = symbols[index];
        numerals[index].value = values[index];
    }   
}

