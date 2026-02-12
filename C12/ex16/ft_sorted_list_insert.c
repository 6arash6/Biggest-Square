#include "ft_list.h"
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)(void *, void *)) {
    t_list *new = ft_create_elem(data);
    if (!new) return;
    if (!*begin_list || cmp((*begin_list)->data, data) > 0) {
        new->next = *begin_list;
        *begin_list = new;
        return;
    }
    t_list *cur = *begin_list;
    while (cur->next && cmp(cur->next->data, data) <= 0)
        cur = cur->next;
    new->next = cur->next;
    cur->next = new;
}
