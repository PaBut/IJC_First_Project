#include "ppm.h"
#include <stdlib.h>
//#include "error.c"

#define COORDINATE_LIMIT 16000

struct ppm* ppm_read(const char * filename){
    FILE *file;
    file = fopen(filename, "r");
    unsigned x,y, color_depth;
    if(file == NULL){
        // warning("ppm_read: Could\'t open the file");
        return NULL;
    }
    if(getc(file) != 'P' || getc(file) != '6' ||
     fscanf(file, "%u %u", &x, &y) != 2 ||
     fscanf(file, "%u", &color_depth) != 1 ||
     color_depth != 255){
        //warning("ppm_read: Wrong file format");
        fclose(file);
        return NULL;
    }
    //symbol \n
    getc(file);
    if(x > COORDINATE_LIMIT || y > COORDINATE_LIMIT){
        // warning("ppm_read: %u is out allowed range(%u)", x > COORDINATE_LIMIT ? x : y, (unsigned)COORDINATE_LIMIT);
        fclose(file);
        return NULL;
    }
    struct ppm* obj = (struct ppm*)malloc(sizeof(struct ppm) + sizeof(char) * 3 * x * y);
    if(obj == NULL){
        // warning("ppm_read: Memory allocation error");
        fclose(file);
        return NULL;
    }
    obj->xsize = x;
    obj->ysize = y;
    if(obj->data == NULL){
        // warning("ppm_read: Memory allocation error");
        free(obj);
        fclose(file);
        return NULL;
    }
    char c;
    for(int i = 0; (c = getc(file)) != EOF; i++){
        obj->data[i] = c;
    }
    fclose(file);

    return obj;
}

void ppm_free(struct ppm *p){
    free(p);
}