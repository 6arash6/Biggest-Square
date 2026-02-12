#include "ft_list.h"
void ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *)) {
    if (!begin_list || !*begin_list || !(*begin_list)->next)
        return;
    int swapped;
    t_list *ptr;
    t_list *lptr = NULL;
    do {
        swapped = 0;
        ptr = *begin_list;
        while (ptr->next != lptr) {
            if (cmp(ptr->data, ptr->next->data) > 0) {
                void *tmp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = tmp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}
