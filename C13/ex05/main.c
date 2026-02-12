#include <stdio.h>
#include "ft_btree.h"
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
t_btree *btree_create_node(void *item);
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
int main(void) {
    int x = 42, y = 24, z = 7;
    t_btree *root = btree_create_node(&x);
    btree_insert_data(&root, &y, cmp);
    btree_insert_data(&root, &z, cmp);
    int ref = 24;
    void *found = btree_search_item(root, &ref, cmp);
    if (found)
        printf("%d\n", *(int *)found); // Output: 24
    else
        printf("Not found\n");
    return 0;
}
