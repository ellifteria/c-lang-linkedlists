#include "../src/x308-libsll.h"
#include "../src/x308-libgenptr.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void tst_with_int(void) {
    // DONE rewrite the below for sll functions
    sll_t my_sll = NULL;
    int val1 = 2;
    int val2 = 10;
    int val3 = 5;
    int val4 = 4;
    int val5 = 3;
    int val6 = 100;
    my_sll = sll_create(&val1);
    my_sll = sll_insert_front(my_sll, &val2);
    my_sll = sll_insert_front(my_sll, &val3);
    my_sll = sll_insert_front(my_sll, &val4);
    my_sll = sll_insert_front(my_sll, &val5);
    sll_print(my_sll, print_int);
    printf("len: %d\n", sll_len(my_sll));
    printf("last val: ");
    sll_print(sll_last(my_sll), print_int);
    printf("last val: %d\n", *((int*)sll_node_data(sll_last(my_sll))));
    my_sll = sll_insert_end(my_sll, &val6);
    sll_print(my_sll, print_int);
    printf("first val: %d\n", *((int*)sll_node_data(my_sll)));
    printf("last val: %d\n", *((int*)sll_node_data(sll_last(my_sll))));
    printf("last val: ");
    sll_print(sll_last(my_sll), print_int);
    printf("len: %d\n", sll_len(my_sll));
    sll_destroy(my_sll, do_nothing_void_ptr);
}

void tst_with_un_malloced_str(void) {
    // DONE rewrite the below for sll functions
    sll_t my_sll = NULL;
    my_sll = sll_create("A");
    my_sll = sll_insert_front(my_sll, "B");
    my_sll = sll_insert_front(my_sll, "C");
    my_sll = sll_insert_front(my_sll, "D");
    my_sll = sll_insert_front(my_sll, "E");
    sll_print(my_sll, print_str);
    printf("len: %d\n", sll_len(my_sll));
    printf("last val: ");
    sll_print(sll_last(my_sll), print_str);
    printf("last val: %s\n", (char*)sll_node_data(sll_last(my_sll)));
    my_sll = sll_insert_end(my_sll, "F");
    sll_print(my_sll, print_str);
    printf("first val: %s\n", (char*)sll_node_data(my_sll));
    printf("last val: %s\n", (char*)sll_node_data(sll_last(my_sll)));
    printf("last val: ");
    sll_print(sll_last(my_sll), print_str);
    printf("len: %d\n", sll_len(my_sll));
    sll_destroy(my_sll, do_nothing_void_ptr);
}

int main(void) {
    tst_with_int();
    printf("\n");
    tst_with_un_malloced_str();
    return 0;
}