#include <stdlib.h>
#include "ft_list.h"
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *)) {
    t_list *cur = *begin_list;
    t_list *prev = NULL;
    while (cur) {
        if (cmp(cur->data, data_ref) == 0) {
            t_list *to_remove = cur;
            if (prev)
                prev->next = cur->next;
            else
                *begin_list = cur->next;
            cur = cur->next;
            free_fct(to_remove->data);
            free(to_remove);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}
