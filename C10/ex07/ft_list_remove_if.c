// Implement ft_list_remove_if according to 42 Piscine C10 standard
#include <stdlib.h>
#include <string.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    t_list *cur = *begin_list;
    t_list *prev = NULL;
    while (cur) {
        if (cmp(cur->data, data_ref) == 0) {
            t_list *tmp = cur;
            if (prev)
                prev->next = cur->next;
            else
                *begin_list = cur->next;
            cur = cur->next;
            free(tmp);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}
