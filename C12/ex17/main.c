#include <stdio.h>
#include "ft_list.h"
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)(void *, void *));
t_list *ft_create_elem(void *data);
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
int main(void) {
    int x = 7, y = 24, z = 42, w = 15;
    t_list *head1 = ft_create_elem(&x);
    t_list *head2 = ft_create_elem(&y);
    t_list *second2 = ft_create_elem(&z);
    t_list *third2 = ft_create_elem(&w);
    head2->next = second2;
    second2->next = third2;
    ft_sorted_list_merge(&head1, head2, cmp);
    for (t_list *cur = head1; cur; cur = cur->next)
        printf("%d ", *(int *)cur->data);
    printf("\n");
    return 0;
}
