#include "bitset.h"
#include <stdio.h>
#include <assert.h>


int main(){
    bitset_t arr;
    bitset_create(arr, 1000LU);
    bitset_setbit(arr, 5, 2);
    printf("%ld", bitset_getbit(arr, 4));
    bitset_free(arr);

    return 0;
}