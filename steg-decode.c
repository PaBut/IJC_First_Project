// steg-decode.c
// IJC-DU1 Solution, task b), 19.03.2023
// Author: Pavlo Butenko, FIT
// Compiled with: gcc 10.2
// Decoding ppm image to get decoded message

#include "bitset.h"
#include <stdio.h>
#include <assert.h>
#include "math.h"
#include "ppm.h"
#include "error.h"
#include "eratosthenes.c"


int main(int argc, char* argv[]){
    if(argc != 2){
        error_exit("main: Invalid amount of arguments, name of file is not specified");
    }
    struct ppm* image = ppm_read(argv[1]);
    if(image == NULL){
        exit(EXIT_FAILURE);
    }
    unsigned long N = 3 * image->xsize * image->ysize;
    bitset_t arr;
    bitset_alloc(&arr, N + 1);
    arr = eratosthenes(arr);
    int primary_count = 0;
    
    
    for(unsigned long i = 101; i < N; i++){
        if(bitset_getbit(arr, i) == 0){
            primary_count++;
        }
    }


    int bit_pos = 0;
    int str_pos = 0;
    char c = 0;
    int g = 0;
    char* str = malloc(primary_count * sizeof(char) / 8);
    for(unsigned long i = 101; i < N; i++){
        if(bitset_getbit(arr, i) == 0){
            g = image->data[i] & 1;
            if(g == 0){
                c &= ~(g << bit_pos++);
            }
            else{
                c |= g << bit_pos++;
            }
            if(bit_pos == 8){
                bit_pos = 0;
                str[str_pos++] = c;
                if(c == '\0'){
                    break;  
                }
                c = 0;
            }

        }
    }

    bitset_free(arr);
    ppm_free(image);

    if(c != '\0'){
        free(str);
        error_exit("There's no end in the encoded message");
    }

    printf("%s\n", str);
    
    free(str);
    return 0;
}
