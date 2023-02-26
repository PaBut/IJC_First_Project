#include "bitset.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "math.h"
#include "ppm.h"


void eratosthenes(unsigned long N){
    bitset_t arr = 0;
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
    int count = 0;
    for(unsigned long i = N; i > 0 && count < 10; i--){
        if(bitset_getbit(arr, i) == 0){
            printf("%lu is a prime number\n", i);
            count++;
        }
    }
    bitset_free(arr);
}

int main(){
    clock_t start = clock();
    eratosthenes(230000000LU);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}

