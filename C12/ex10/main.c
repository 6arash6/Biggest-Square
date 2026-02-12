#include <stdio.h>
#include "ft_list.h"
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)(void *, void *));
t_list *ft_create_elem(void *data);
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
void print(void *data) { printf("%d ", *(int *)data); }
int main(void) {
    int x = 42, y = 24, z = 42;
    t_list *head = ft_create_elem(&x);
    t_list *second = ft_create_elem(&y);
    t_list *third = ft_create_elem(&z);
    head->next = second;
    second->next = third;
    int ref = 42;
    ft_list_foreach_if(head, print, &ref, cmp);
    printf("\n");
    return 0;
}
