#include <stdio.h>
#include "ft_list.h"
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42;
    t_list *elem = ft_create_elem(&x);
    printf("%d\n", *(int *)elem->data); // Output: 42
    return 0;
}
