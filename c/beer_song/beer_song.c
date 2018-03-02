#include "beer_song.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * verse(char * response, int cant_bottles) {
    char * remaining_bottles = ( cant_bottles == 2 ) ? "bottle" : "bottles";
    if (cant_bottles == 1) {
        remaining_bottles = "no more bottles";
        sprintf (response,
           "%d %s %s %s, %d %s %s.\n"
           "%s it %s %s %s %s.\n",
           cant_bottles, BOTTLE, OF_BEER, ON_THE_WALL, cant_bottles, BOTTLE, OF_BEER, TAKE, DOWN_AND_PASS, remaining_bottles, OF_BEER, ON_THE_WALL);
    }
    else if(cant_bottles == 0){
     remaining_bottles = "no more bottles";
     sprintf(response,
         "No more %ss %s %s, %s %s.\n"
         "Go to the store and buy some more, 99 %ss %s %s.\n",
         BOTTLE, OF_BEER, ON_THE_WALL, remaining_bottles, OF_BEER, BOTTLE, OF_BEER, ON_THE_WALL);
 }
 else {
    sprintf (response,
        "%d %ss %s %s, %d %ss %s.\n"
        "%s one %s %d %s %s %s.\n",
        cant_bottles, BOTTLE, OF_BEER, ON_THE_WALL, cant_bottles, BOTTLE, OF_BEER, TAKE, DOWN_AND_PASS, cant_bottles -1, remaining_bottles, OF_BEER, ON_THE_WALL);   
}    
return response;
}

void sing(char * response, int max, int min) {
    char * song = calloc(1, BUFFER_SIZE); 
    for (int cant_bottles = max; cant_bottles > min; cant_bottles--)
        strcat(song, strcat(verse(response, cant_bottles), "\n"));    
    strcpy(response, strcat(song, verse(response, min)));
    destroy(song);
}

void destroy(void* ptr) {
    free(ptr);
    ptr = NULL;
}

