#include <stdio.h>
#include "ft_list.h"
t_list *ft_list_last(t_list *begin_list);
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42, y = 24;
    t_list *head = ft_create_elem(&x);
    t_list *second = ft_create_elem(&y);
    head->next = second;
    t_list *last = ft_list_last(head);
    printf("%d\n", *(int *)last->data); // Output: 24
    return 0;
}
