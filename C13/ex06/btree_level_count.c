#include "ft_btree.h"
int btree_level_count(t_btree *root) {
    if (!root) return 0;
    int left = btree_level_count(root->left);
    int right = btree_level_count(root->right);
    return (left > right ? left : right) + 1;
}
