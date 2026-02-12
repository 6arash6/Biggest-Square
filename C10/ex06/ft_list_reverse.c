// Implement ft_list_reverse according to 42 Piscine C10 standard
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

void ft_list_reverse(t_list **begin_list)
{
    t_list *prev = NULL;
    t_list *cur = *begin_list;
    t_list *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *begin_list = prev;
}
