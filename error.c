// error.c
// IJC-DU1 Solution, task b), 19.03.2023
// Author: Pavlo Butenko, FIT
// Compiled with: gcc 10.2
// Displaying errors/warnings

#include "error.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr,"Warning: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}
void error_exit(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}