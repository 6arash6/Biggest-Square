#include <stdio.h>
#include "ft_list.h"
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
t_list *ft_create_elem(void *data);
int main(void) {
    int x = 42, y = 24, z = 7;
    t_list *head1 = ft_create_elem(&x);
    t_list *head2 = ft_create_elem(&y);
    t_list *second2 = ft_create_elem(&z);
    head2->next = second2;
    ft_list_merge(&head1, head2);
    for (t_list *cur = head1; cur; cur = cur->next)
        printf("%d ", *(int *)cur->data);
    printf("\n");
    return 0;
}
