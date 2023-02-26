#include "error.h"
#include <stdarg.h>
#include <stdio.h>

void warning(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr,"Warning: ");
    vfprintf(stderr, fmt, args);
}
void error_exit(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, args);
    exit(1);
}