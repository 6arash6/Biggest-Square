#include <stdio.h>
#include "ft_list.h"
void ft_list_reverse_fun(t_list *begin_list);
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42, y = 24, z = 7;
    t_list *head = ft_create_elem(&x);
    t_list *second = ft_create_elem(&y);
    t_list *third = ft_create_elem(&z);
    head->next = second;
    second->next = third;
    ft_list_reverse_fun(head);
    for (t_list *cur = head; cur; cur = cur->next)
        printf("%d ", *(int *)cur->data);
    printf("\n");
    return 0;
}
