#ifndef FT_BTREE_H
#define FT_BTREE_H

typedef struct s_btree {
    void *item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

t_btree *btree_create_node(void *item);
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));

#endif
