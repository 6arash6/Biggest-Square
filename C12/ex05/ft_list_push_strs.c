#include "ft_list.h"
t_list *ft_list_push_strs(int size, char **strs) {
    t_list *head = NULL;
    for (int i = 0; i < size; i++) {
        t_list *new = ft_create_elem(strs[i]);
        if (!new) return NULL;
        new->next = head;
        head = new;
    }
    return head;
}
