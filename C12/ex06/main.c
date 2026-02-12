#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
void ft_list_clear(t_list **begin_list, void (*free_fct)(void *));
t_list *ft_create_elem(void *data);
int main(void) {
    int *x = malloc(sizeof(int));
    *x = 42;
    t_list *head = ft_create_elem(x);
    ft_list_clear(&head, free);
    printf("%p\n", (void *)head); // Output: 0
    return 0;
}
