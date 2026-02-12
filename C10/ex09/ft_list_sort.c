// Implement ft_list_sort according to 42 Piscine C10 standard
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

void ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
    if (!*begin_list)
        return;
    t_list *cur, *next;
    void *tmp;
    int swapped;
    do {
        swapped = 0;
        cur = *begin_list;
        while (cur->next) {
            next = cur->next;
            if (cmp(cur->data, next->data) > 0) {
                tmp = cur->data;
                cur->data = next->data;
                next->data = tmp;
                swapped = 1;
            }
            cur = cur->next;
        }
    } while (swapped);
}
