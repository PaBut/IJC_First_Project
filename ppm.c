#include "ppm.h"
#include <stdlib.h>
#include "error.c"

#define COORDINATE_LIMIT 16000

struct ppm* ppm_read(const char * filename){
    FILE *file;
    file = fopen(filename);
    unsigned x,y, color_depth;
    if(file == NULL){
        warning("ppm_read: Could\'t open the file");
    }
    if(getc(file) != 'P' || getc(file) != '6' ||
     fscanf(file, "%u %u", &x, &y) != 2 ||
     fscanf(file, "%u", &color_depth) != 1 ||
     color_depth != 255){
        warning("ppm_read: Wrong file format");
        return NULL;
    }
    if(x > COORDINATE_LIMIT || y > COORDINATE_LIMIT){
        warning("ppm_read: %u is out allowed range(%u)", x > COORDINATE_LIMIT ? x : y, (unsigned)COORDINATE_LIMIT);
    }
    struct ppm* obj = (struct ppm*)malloc(sizeof(struct ppm));
    if(obj == NULL){
        warning("ppm_read: Memory allocation error");
        return NULL;
    }
    obj->xsize = x;
    obj->ysize = y;
    obj->data = (char*)malloc(3 * x * y);
    if(obj->data == NULL){
        warning("ppm_read: Memory allocation error");
        free(obj);
        return NULL;
    }
    char c;
    for(int i = 0; (c = getc(file)) != EOF; i++){
        obj->data[i] = c;
    }

    return obj;
}

void ppm_free(struct ppm *p){
    free(p->data);
    free(p);
}