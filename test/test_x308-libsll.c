#include "../src/x308-libsll.h"
#include "../src/x308-libgenptr.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void tst1(void) {
    // TODO rewrite the below for sll functions
    sll_t my_sll = NULL;
    my_sll = sll_create(2);
    my_sll = sll_insert_front(my_sll, 10);
    my_sll = sll_insert_front(my_sll, 5);
    my_sll = sll_insert_front(my_sll, 4);
    my_sll = sll_insert_front(my_sll, 3);
    sll_print(my_sll);
    printf("len: %d\n", sll_len(my_sll));
    printf("last val: ");
    sll_print(sll_last(my_sll));
    printf("last val: %d\n", sll_node_val(sll_last(my_sll)));
    my_sll = sll_insert_end(my_sll, 100);
    sll_print(my_sll);
    printf("first val: %d\n", sll_node_val(my_sll));
    printf("last val: %d\n", sll_node_val(sll_last(my_sll)));
    printf("last val: ");
    sll_print(sll_last(my_sll));
    printf("len: %d\n", sll_len(my_sll));
    sll_destroy(my_sll);
}

int main(void) {
    tst1();
    return 0;
}