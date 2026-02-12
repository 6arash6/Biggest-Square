#include <stdio.h>
#include "ft_btree.h"
t_btree *btree_create_node(void *item);
int main(void) {
    int x = 42;
    t_btree *node = btree_create_node(&x);
    printf("%d\n", *(int *)node->item); // Output: 42
    return 0;
}
