    #include <stdio.h>
    #include <limits.h>
    #include <stdlib.h>
    #include <assert.h>


    typedef unsigned long* bitset_t;
    typedef unsigned long bitset_index_t;

    #define MAX_COUNT (unsigned long)(CHAR_BIT*sizeof(unsigned long))

    #ifndef USE_INLINE

    #define bitset_create(bitset, size)({\
        /*_Static_assert(size > 0, "Size can't be less than 0");*/\
        bitset_alloc(bitset, size);\
    })

    #define bitset_alloc(bitset, size)({\
        unsigned long bitset_size = (unsigned long)size / MAX_COUNT + 2;\
        (*bitset) = (bitset_t)malloc(bitset_size * sizeof(unsigned long));\
        /*assert((*bitset) != NULL, "Memory allocation error");*/\
        (*bitset)[0] = size;\
        for(unsigned long i = 1; i < bitset_size; i++){\
            (*bitset)[i] = 0UL;\
        }\
    })


    #define bitset_getbit(bitset, index)({\
    unsigned long simple_index = (unsigned long)index / MAX_COUNT + 1;\
    unsigned long bit_index = index % MAX_COUNT;\
    unsigned long tmp = bitset[simple_index] & (1UL << bit_index);\
    tmp == 1UL << bit_index ? 1UL : 0UL;\
    })

    #define bitset_setbit(bitset, index, value) ({\
    unsigned long simple_index = (unsigned long)index / MAX_COUNT + 1;\
    unsigned long bit_index = index % MAX_COUNT;\
    if(value == 0){\
        bitset[simple_index] &= 0UL << bit_index;\
    }else{\
        bitset[simple_index] |= 1UL << bit_index;\
    }\
    })
    #define bitset_size(bitset) bitset[0]
    #define bitset_free(bitset) free(bitset)

    #else
    //////////////////////////////////////////////////////////////////////////////////////////

    static inline void bitset_alloc(bitset_t* bitset, unsigned long size){
        unsigned long bitset_size = (unsigned long)size / MAX_COUNT + 2;
        (*bitset) = (bitset_t)malloc(bitset_size * sizeof(unsigned long));
        (*bitset)[0] = size;
        for(unsigned long i = 1; i < bitset_size; i++){
            (*bitset)[i] = 0UL;
        }
    }

    static inline void bitset_create(bitset_t* bitset, unsigned long size){
        //_Static_assert(size > 0, "Size can't be less than 0");
        bitset_alloc(bitset, size);
    }

    static inline unsigned long bitset_getbit(bitset_t bitset, unsigned long index){
        unsigned long simple_index = (unsigned long)index / MAX_COUNT + 1;
        unsigned long bit_index = index % MAX_COUNT;
        unsigned long tmp = bitset[simple_index] & (1UL << bit_index);
        return tmp == 1UL << bit_index ? 1UL : 0UL;
    }

    static inline void bitset_setbit(bitset_t bitset, unsigned long index, unsigned long value){
        unsigned long simple_index = (unsigned long)index / MAX_COUNT + 1;
        unsigned long bit_index = index % MAX_COUNT;
        if(value == 0){
            bitset[simple_index] &= 0UL << bit_index;
        }else{
            bitset[simple_index] |= 1UL << bit_index;
        }
    }

    static inline unsigned long bitset_size(bitset_t bitset){
        return bitset[0];
    }

    static inline void bitset_free(bitset_t bitset){
        free(bitset);
    }

    #endif












