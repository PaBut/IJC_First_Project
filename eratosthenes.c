#include "bitset.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>


int main(){
    clock_t start = clock();
    bitset_t arr = 0;
    bitset_create(&arr, 1000LU);
    bitset_setbit(arr, 5, 2);
    // bitset_setbit(arr, 5, 0);
    printf("%ld", bitset_getbit(arr, 5));
    bitset_free(arr);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}

// void eratosthenes(){

// }