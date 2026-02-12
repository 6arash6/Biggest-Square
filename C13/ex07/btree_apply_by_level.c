#include <stdlib.h>
#include "ft_btree.h"
static int max(int a, int b) { return a > b ? a : b; }
static int btree_level_count(t_btree *root) {
    if (!root) return 0;
    return 1 + max(btree_level_count(root->left), btree_level_count(root->right));
}
static void apply_level(t_btree *root, void (*applyf)(void *, int, int), int level, int is_first) {
    if (!root) return;
    if (level == 0)
        applyf(root->item, level, is_first);
    else {
        apply_level(root->left, applyf, level - 1, is_first);
        apply_level(root->right, applyf, level - 1, 0);
    }
}
void btree_apply_by_level(t_btree *root, void (*applyf)(void *, int, int)) {
    int levels = btree_level_count(root);
    for (int i = 0; i < levels; i++)
        apply_level(root, applyf, i, 1);
}
