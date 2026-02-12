// Implement ft_list_size according to 42 Piscine C10 standard
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

int ft_list_size(t_list *begin_list)
{
    int count = 0;
    while (begin_list) {
        count++;
        begin_list = begin_list->next;
    }
    return count;
}
