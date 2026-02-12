#include "ft_list.h"
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)(void *, void *)) {
    t_list *cur2 = begin_list2;
    while (cur2) {
        ft_sorted_list_insert(begin_list1, cur2->data, cmp);
        cur2 = cur2->next;
    }
}
