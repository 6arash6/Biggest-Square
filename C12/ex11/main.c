#include <stdio.h>
#include "ft_list.h"
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *));
t_list *ft_create_elem(void *data);
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
int main(void) {
    int x = 42, y = 24, z = 7;
    t_list *head = ft_create_elem(&x);
    t_list *second = ft_create_elem(&y);
    t_list *third = ft_create_elem(&z);
    head->next = second;
    second->next = third;
    int ref = 24;
    t_list *found = ft_list_find(head, &ref, cmp);
    if (found)
        printf("%d\n", *(int *)found->data); // Output: 24
    else
        printf("Not found\n");
    return 0;
}
