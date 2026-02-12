#include "ft_btree.h"
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
    if (!root) return NULL;
    int cmp = cmpf(data_ref, root->item);
    if (cmp == 0)
        return root->item;
    else if (cmp < 0)
        return btree_search_item(root->left, data_ref, cmpf);
    else
        return btree_search_item(root->right, data_ref, cmpf);
}
