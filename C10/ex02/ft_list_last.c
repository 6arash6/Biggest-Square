// Implement ft_list_last according to 42 Piscine C10 standard
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *ft_list_last(t_list *begin_list)
{
    if (!begin_list)
        return NULL;
    while (begin_list->next)
        begin_list = begin_list->next;
    return begin_list;
}
