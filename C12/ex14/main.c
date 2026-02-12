#include <stdio.h>
#include "ft_list.h"
void ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
t_list *ft_create_elem(void *data);
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
int main(void) {
    int x = 42, y = 24, z = 7;
    t_list *head = ft_create_elem(&x);
    t_list *second = ft_create_elem(&y);
    t_list *third = ft_create_elem(&z);
    head->next = second;
    second->next = third;
    ft_list_sort(&head, cmp);
    for (t_list *cur = head; cur; cur = cur->next)
        printf("%d ", *(int *)cur->data);
    printf("\n");
    return 0;
}
