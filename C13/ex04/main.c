#include <stdio.h>
#include "ft_btree.h"
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
t_btree *btree_create_node(void *item);
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
int main(void) {
    int x = 42, y = 24, z = 7, w = 50;
    t_btree *root = btree_create_node(&x);
    btree_insert_data(&root, &y, cmp);
    btree_insert_data(&root, &z, cmp);
    btree_insert_data(&root, &w, cmp);
    void print(void *item) { printf("%d ", *(int *)item); }
    btree_apply_prefix(root, print);
    printf("\n");
    return 0;
}
