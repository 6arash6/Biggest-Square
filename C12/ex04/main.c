#include <stdio.h>
#include "ft_list.h"
void ft_list_push_back(t_list **begin_list, void *data);
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42, y = 24;
    t_list *head = ft_create_elem(&x);
    ft_list_push_back(&head, &y);
    printf("%d %d\n", *(int *)head->data, *(int *)head->next->data); // Output: 42 24
    return 0;
}
