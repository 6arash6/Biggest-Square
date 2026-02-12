#include <stdlib.h>
#include "ft_list.h"

t_list *ft_list_push_back(t_list **begin_list, void *data) {
    t_list *new = malloc(sizeof(t_list));
    if (!new) return NULL;
    new->data = data;
    new->next = NULL;
    if (!*begin_list) {
        *begin_list = new;
        return new;
    }
    t_list *cur = *begin_list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
    return new;
}
