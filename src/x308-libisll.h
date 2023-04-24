/*
* // TODO add header comment here
*/

// TODO add imports if needed

typedef struct isll_node* isll_t;

extern int isll_node_val(isll_t);

extern int isll_len(isll_t);

extern isll_t isll_last(isll_t);

extern isll_t isll_create(int);

extern isll_t isll_insert_front(isll_t, int);

extern isll_t isll_insert_end(isll_t, int);

extern void isll_destroy(isll_t);

extern void isll_print(isll_t);
