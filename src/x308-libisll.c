#include "x308-libisll.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

struct isll_node
{
    int val;
    struct isll_node* next;
};

int isll_node_val(isll_t isll) {
    return isll->val;
}

int isll_len(isll_t isll) {
    if (!isll) {
        return -1;
    }

    int length = 1;

    isll_t node = isll;

    while (node->next) {
        ++length;
        node = node->next;
    }

    return length;
}

isll_t isll_get(isll_t isll, int index) {
    if (index >= isll_len(isll) || index < 0) {
        printf("error: invalid index; return given isll");
        return isll;
    }

    int i = 0;
    while (i < index) {
        isll = isll->next;
    }

    return isll;
}

isll_t isll_last(isll_t isll) {
    while ((isll->next)) {
        isll = isll->next;
    }

    return isll;
}

isll_t isll_create(int val) {
    isll_t isll = malloc(sizeof(isll_t));
    isll->val = val;
    isll->next = NULL;
    return isll;
}

isll_t isll_insert_front(isll_t isll, int val){
    isll_t new_head = isll_create(val);
    new_head->next = isll;
    return new_head;
}

isll_t isll_insert_end(isll_t isll, int val){
    isll_t curr_last = isll_last(isll);
    isll_t new_last = isll_create(val);
    curr_last->next = new_last;
    return isll;
}

isll_t isll_insert_at(isll_t isll, int val, int index) {
    if (index == 0) {
        return isll_insert_front(isll, val);
    }

    if (index == isll_len(isll) - 1) {
        return isll_insert_end(isll, val);
    }

    isll_t curr_node = isll_get(isll, index);
    isll_t new_node = isll_create(val);
    new_node->next = curr_node->next;
    curr_node->next = new_node;
    return isll;
}

// TODO add remove methods

void isll_destroy(isll_t isll) {
    if(!isll->next) {
        free(isll);
        return;
    }

    isll_destroy(isll->next);
    free(isll);
}

void isll_print(isll_t isll) {
    while (isll) {
        printf("%d", isll->val);
        if (isll->next) {
            printf(" -> ");
        }
        isll = isll->next;
    }
    printf("\n");
}
