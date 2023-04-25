/*
* // TODO add header comment here
*/

// TODO add imports if needed

typedef struct sll_node* sll_t;

extern int sll_node_val(sll_t);

extern int sll_len(sll_t);

extern sll_t sll_get(sll_t, int);

extern sll_t sll_last(sll_t);

extern sll_t sll_create(void*);

extern sll_t sll_insert_front(sll_t, void*);

extern sll_t sll_insert_end(sll_t, void*);

extern sll_t sll_insert_at(sll_t, void*, int);

extern void sll_destroy(sll_t, void (*f)(void*));

extern void sll_print(sll_t, int (*f)(void*));
