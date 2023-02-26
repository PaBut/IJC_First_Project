#include "bitset.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "math.h"
#include "ppm.c"


bitset_t eratosthenes(unsigned long N){
    bitset_t arr;
    bitset_create(&arr, N + 1);
    bitset_setbit(arr, 0, 1);
    bitset_setbit(arr, 1, 1);
    for(unsigned long i = 2; i < floor(sqrt(N)); i++){
        if(bitset_getbit(arr, i) == 0){
            for(unsigned long n = i * i; n <= N; n+=i){
                bitset_setbit(arr, n, 1); 
            }
        }
    }
    return arr;
}

/*int main(){
    clock_t start = clock();
    unsigned long N = 230000000LU;
    bitset_t arr = eratosthenes(N);
    int count = 0;
    for(unsigned long i = N; i > 0 && count < 10; i--){
        if(bitset_getbit(arr, i) == 0){
            printf("%lu is a prime number\n", i);
            count++;
        }
    }
    bitset_free(arr);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}*/

int main(int argc, char* argv[]){
    if(argc != 2){
        error_exit("main: Invalid amount of arguments, name of file is not specified");
    }
    clock_t start = clock();
    struct ppm* image = ppm_read(argv[1]);
    unsigned long N = 3 * image->xsize * image->ysize;
    bitset_t arr = eratosthenes(N);
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
    printf("\n%s\n", str);
    
    bitset_free(arr);
    ppm_free(image);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}

