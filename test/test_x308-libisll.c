#include "../src/x308-libisll.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void tst1(void) {
    isll_t my_isll = NULL;
    my_isll = isll_create(2);
    my_isll = isll_insert_front(my_isll, 10);
    my_isll = isll_insert_front(my_isll, 5);
    my_isll = isll_insert_front(my_isll, 4);
    my_isll = isll_insert_front(my_isll, 3);
    isll_print(my_isll);
    printf("len: %d\n", isll_len(my_isll));
    printf("last val: ");
    isll_print(isll_last(my_isll));
    printf("last val: %d\n", isll_node_val(isll_last(my_isll)));
    my_isll = isll_insert_end(my_isll, 100);
    isll_print(my_isll);
    printf("first val: %d\n", isll_node_val(my_isll));
    printf("last val: %d\n", isll_node_val(isll_last(my_isll)));
    printf("last val: ");
    isll_print(isll_last(my_isll));
    printf("len: %d\n", isll_len(my_isll));
    isll_destroy(my_isll);
}

int main(void) {
    tst1();
    return 0;
}