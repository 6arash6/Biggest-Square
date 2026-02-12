#include <stdio.h>
#include <stdlib.h>
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
t_list *ft_list_push_back(t_list **begin_list, void *data);

int main(void)
{
    t_list *head1 = NULL, *head2 = NULL;
    int a = 42, b = 24, c = 7;
    ft_list_push_back(&head1, &a);
    ft_list_push_back(&head2, &b);
    ft_list_push_back(&head2, &c);
    ft_list_merge(&head1, head2);
    printf("%d %d %d\n", *(int *)head1->data, *(int *)head1->next->data, *(int *)head1->next->next->data); // 42 24 7
    return 0;
}
