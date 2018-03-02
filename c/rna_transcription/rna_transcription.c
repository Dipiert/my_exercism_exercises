#include "rna_transcription.h"

char* to_rna(const char* dna) {

    char * ret = calloc(1, BUFFER_SIZE);
    for(size_t index = 0; index < strlen(dna); index++){
        if     (dna[index] == 'G') strcat(ret, "C");
        else if(dna[index] == 'C') strcat(ret, "G");
        else if(dna[index] == 'T') strcat(ret, "A");
        else if(dna[index] == 'A') strcat(ret, "U");
        else{
            free(ret);
            return 0;
        } 
    }
    return ret;
}

