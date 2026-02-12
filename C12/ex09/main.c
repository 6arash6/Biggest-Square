#include <stdio.h>
#include "ft_list.h"
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42, y = 24, z = 7;
    t_list *head = ft_create_elem(&x);
    t_list *second = ft_create_elem(&y);
    t_list *third = ft_create_elem(&z);
    head->next = second;
    second->next = third;
    void print(void *data) { printf("%d ", *(int *)data); }
    ft_list_foreach(head, print);
    printf("\n");
    return 0;
}
