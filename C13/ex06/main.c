#include <stdio.h>
#include "ft_btree.h"
int btree_level_count(t_btree *root);
t_btree *btree_create_node(void *item);
int main(void) {
    int x = 42, y = 24, z = 7;
    t_btree *root = btree_create_node(&x);
    root->left = btree_create_node(&y);
    root->right = btree_create_node(&z);
    printf("%d\n", btree_level_count(root)); // Output: 2
    return 0;
}
