#include "ft_list.h"
void ft_list_push_back(t_list **begin_list, void *data) {
    t_list *new = ft_create_elem(data);
    if (!new) return;
    if (!*begin_list) {
        *begin_list = new;
        return;
    }
    t_list *cur = *begin_list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}
