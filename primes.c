#include "eratosthenes.c"
// #include "bitset.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>

int main(){
    clock_t start = clock();
    unsigned long N = 230000000LU;
    bitset_t arr;
    bitset_create(&arr, N + 1);
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