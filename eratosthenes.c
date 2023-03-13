#include "bitset.h"
#include <assert.h>
#include "math.h"


bitset_t eratosthenes(bitset_t arr){
    unsigned long size = bitset_size(arr);
    bitset_setbit(arr, 0, 1);
    bitset_setbit(arr, 1, 1);
    for(unsigned long i = 2; i < floor(sqrt(size)); i++){
        if(bitset_getbit(arr, i) == 0){
            for(unsigned long n = i * i; n <= size; n+=i){
                bitset_setbit(arr, n, 1); 
            }
        }
    }
    return arr;
}