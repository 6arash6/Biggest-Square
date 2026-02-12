#include <stdio.h>
#include "ft_list.h"
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42, y = 24, z = 7;
    t_list *head = ft_create_elem(&x);
    t_list *second = ft_create_elem(&y);
    t_list *third = ft_create_elem(&z);
    head->next = second;
    second->next = third;
    t_list *elem = ft_list_at(head, 2);
    printf("%d\n", *(int *)elem->data); // Output: 7
    return 0;
}
