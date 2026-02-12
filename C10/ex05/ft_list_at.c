// Implement ft_list_at according to 42 Piscine C10 standard
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int i = 0;
    while (begin_list && i < nbr) {
        begin_list = begin_list->next;
        i++;
    }
    return begin_list;
}
