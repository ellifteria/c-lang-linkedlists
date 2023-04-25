#include "x308-libsll.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

struct sll_node
{
    void* data;
    struct sll_node* next;
};

// UNTESTED
void sll_destroy(sll_t sll, void (*destroy)(void*)) {
    if(!sll->next) {
        (*destroy)(sll->data);
        free(sll);
        return;
    }

    sll_destroy(sll->next, (*destroy));
    (*destroy)(sll->data);
    free(sll);
}

// UNTESTED
void sll_print(sll_t sll, int (*print)(void*)) {
    while (sll) {
        (*print)(sll->data);
        if (sll->next) {
            printf(" -> ");
        }
        sll = sll->next;
    }
    printf("\n");
}

