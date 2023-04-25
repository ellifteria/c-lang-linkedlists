#include "x308-libsll.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

struct sll_node
{
    void* data;
    struct sll_node* next;
};

void* sll_node_data(sll_t sll) {
    return sll->data;
}

int sll_len(sll_t sll) {
    if (!sll) {
        return -1;
    }

    int length = 1;

    sll_t node = sll;

    while (node->next) {
        ++length;
        node = node->next;
    }

    return length;
}

// UNTESTED
sll_t sll_get(sll_t sll, int index) {
    if (index >= sll_len(sll) || index < 0) {
        printf("error: invalid index; return given sll");
        return sll;
    }

    int i = 0;
    while (i < index) {
        sll = sll->next;
    }

    return sll;
}

sll_t sll_last(sll_t sll) {
    while ((sll->next)) {
        sll = sll->next;
    }

    return sll;
}

sll_t sll_create(void* data) {
    sll_t sll = malloc(sizeof(struct sll_node));
    sll->data = data;
    sll->next = NULL;
    return sll;
}

sll_t sll_insert_front(sll_t sll, void* data){
    sll_t new_head = sll_create(data);
    new_head->next = sll;
    return new_head;
}

sll_t sll_insert_end(sll_t sll, void* data){
    sll_t curr_last = sll_last(sll);
    sll_t new_last = sll_create(data);
    curr_last->next = new_last;
    return sll;
}

// UNTESTED
sll_t sll_insert_at(sll_t sll, void* data, int index) {
    if (index == 0) {
        return sll_insert_front(sll, data);
    }

    if (index == sll_len(sll) - 1) {
        return sll_insert_end(sll, data);
    }

    sll_t curr_node = sll_get(sll, index);
    sll_t new_node = sll_create(data);
    new_node->next = curr_node->next;
    curr_node->next = new_node;
    return sll;
}

// TODO add remove methods


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

