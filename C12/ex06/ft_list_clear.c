#include <stdlib.h>
#include "ft_list.h"
void ft_list_clear(t_list **begin_list, void (*free_fct)(void *)) {
    t_list *cur = *begin_list;
    while (cur) {
        t_list *next = cur->next;
        free_fct(cur->data);
        free(cur);
        cur = next;
    }
    *begin_list = NULL;
}
