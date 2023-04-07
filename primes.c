// primes.c
// IJC-DU1 Solution, task a), 19.03.2023
// Author: Pavlo Butenko, FIT
// Compiled with: gcc 10.2
// Getting last 10 primary numbers up to specific number

#include "eratosthenes.c"
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define N 230000000LU

int main(){
    clock_t start = clock();
    bitset_t arr;
    bitset_create(&arr, N);
    arr = eratosthenes(arr);
    int count = 0;
    for(unsigned long i = N; i > 0 && count < 10; i--){
        if(bitset_getbit(arr, i) == 0){
            printf("%lu\n", i);
            count++;
        }
    }
    bitset_free(arr);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}