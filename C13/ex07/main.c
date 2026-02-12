#include <stdio.h>
#include "ft_btree.h"
void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
t_btree *btree_create_node(void *item);
void applyf(void *item, int level, int first) { printf("%d:%d:%d ", *(int *)item, level, first); }
int main(void) {
    int x = 42, y = 24, z = 7, w = 50;
    t_btree *root = btree_create_node(&x);
    root->left = btree_create_node(&y);
    root->right = btree_create_node(&z);
    root->left->left = btree_create_node(&w);
    btree_apply_by_level(root, applyf);
    printf("\n");
    return 0;
}
