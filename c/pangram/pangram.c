#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

#include "pangram.h"
#define TOTAL_LETTERS 26


char letters[TOTAL_LETTERS];

bool is_pangram(const char* sentence) {
    memset(letters, 0, TOTAL_LETTERS);
    int letters_count = 0;
    if (!sentence || !strlen(sentence)) return false;
    char* upp_sentence = str_toupper(sentence);
    for (size_t i = 0; i < strlen(upp_sentence); i++) {
        if (is_new_letter(upp_sentence[i]) && is_valid_letter(upp_sentence[i])) {
            letters[letters_count] = upp_sentence[i];
            letters_count++;
        }
    
    }
    return (letters_count == TOTAL_LETTERS);
}

bool is_new_letter(char letter) {
    for (int i = 0; i < TOTAL_LETTERS && letters[i] != '\0'; i++)
        if (letters[i] == letter) return false; 
    return true;
}

bool is_valid_letter(char c) {
    return (c >= 'A' && c <= 'Z');
}

char* str_toupper(const char* sentence) {
    int index = 0;
    size_t str_size = strlen(sentence);
    char* upp_sentence = malloc(str_size);
    strncpy(upp_sentence, sentence, str_size);
    upp_sentence[strlen(sentence)] = '\0';
    while(upp_sentence[index]) {
        upp_sentence[index] = toupper(upp_sentence[index]);
        index++;
    }
    return upp_sentence;
}

