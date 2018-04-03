#include "acronym.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* abbreviate(char* str) {
    if (!str || strlen(str) == 0) return NULL;

    char phrase[strlen(str)];
    char delim[] = " \t\r\n\v\f-";
    char * result = malloc(strlen(str));

    strcpy(phrase,str);

    char* token = strtok(phrase, delim);
    while(token != NULL) {
        char letter = toupper(token[0]);
        strncat (result, &letter, 1);
        token = strtok(NULL, delim);
    }

    return result;
}

