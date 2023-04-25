#include "x308-libgenptr.h"

#include <stdlib.h>
// #include <stddef.h>
#include <stdio.h>

int print_str(void* str) {
    printf("%s", (char*)str);
    return 0;
}

int print_int(void* i) {
    printf("%d", *((int*) i));
    return 0;
}

int print_float(void* f) {
    printf("%f", *((float*) f));
    return 0;
}

// TODO add delete functions to free things

void do_nothing_void_ptr(void* i) {}

// UNTESTED
void free_ptr(void* ptr) {
    free( (char*)ptr);
}
