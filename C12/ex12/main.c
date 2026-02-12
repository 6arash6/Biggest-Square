#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *));
t_list *ft_create_elem(void *data);
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
int main(void) {
    int *x = malloc(sizeof(int)); *x = 42;
    int *y = malloc(sizeof(int)); *y = 24;
    int *z = malloc(sizeof(int)); *z = 42;
    t_list *head = ft_create_elem(x);
    t_list *second = ft_create_elem(y);
    t_list *third = ft_create_elem(z);
    head->next = second;
    second->next = third;
    int ref = 42;
    ft_list_remove_if(&head, &ref, cmp, free);
    for (t_list *cur = head; cur; cur = cur->next)
        printf("%d ", *(int *)cur->data);
    printf("\n");
    return 0;
}
