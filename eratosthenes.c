// eratosthenes.c
// IJC-DU1 Solution, task a), 19.03.2023
// Author: Pavlo Butenko, FIT
// Compiled with: gcc 10.2
// Function using Eratosthenes algorithm sets only bits with primary indexes

#include "bitset.h"
#include <assert.h>
#include "math.h"


bitset_t eratosthenes(bitset_t arr){
    unsigned long size = bitset_size(arr);
    bitset_setbit(arr, 0, 1);
    bitset_setbit(arr, 1, 1);  
    for(unsigned long i = 2; i <= floor(sqrt(size)); i++){
        if(bitset_getbit(arr, i) == 0){
            for(unsigned long n = i * i; n <= size; n+=i){
                bitset_setbit(arr, n, 1); 
            }
        }
    }
    return arr;
}