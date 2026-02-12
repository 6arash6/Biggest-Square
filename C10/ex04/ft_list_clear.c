// Implement ft_list_clear according to 42 Piscine C10 standard
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

void ft_list_clear(t_list **begin_list)
{
    t_list *cur = *begin_list;
    t_list *tmp;
    while (cur) {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    *begin_list = NULL;
}
