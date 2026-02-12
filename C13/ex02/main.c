#include <stdio.h>
#include "ft_btree.h"
void btree_apply_infix(t_btree *root, void (*applyf)(void *));
t_btree *btree_create_node(void *item);
void print(void *item) { printf("%d ", *(int *)item); }
int main(void) {
    int x = 42, y = 24, z = 7;
    t_btree *root = btree_create_node(&x);
    root->left = btree_create_node(&y);
    root->right = btree_create_node(&z);
    btree_apply_infix(root, print);
    printf("\n");
    return 0;
}
