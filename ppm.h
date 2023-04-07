// ppm.h
// IJC-DU1 Solution, task b), 19.03.2023
// Author: Pavlo Butenko, FIT
// Compiled with: gcc 10.2
// Interface for ppm.c

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

