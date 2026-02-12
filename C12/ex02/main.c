#include <stdio.h>
#include "ft_list.h"
int ft_list_size(t_list *begin_list);
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42, y = 24;
    t_list *head = ft_create_elem(&x);
    ft_create_elem(&y)->next = head;
    printf("%d\n", ft_list_size(head)); // Output: 2
    return 0;
}
