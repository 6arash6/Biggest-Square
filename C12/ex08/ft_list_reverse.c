#include "ft_list.h"
void ft_list_reverse(t_list **begin_list) {
    t_list *prev = NULL;
    t_list *cur = *begin_list;
    while (cur) {
        t_list *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *begin_list = prev;
}
