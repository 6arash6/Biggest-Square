#include <stdio.h>
#include <stdlib.h>
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
t_list *ft_list_last(t_list *begin_list);
t_list *ft_list_push_front(t_list **begin_list, void *data);

int main(void)
{
    t_list *head = NULL;
    int a = 42, b = 24, c = 7;
    ft_list_push_front(&head, &a);
    ft_list_push_front(&head, &b);
    ft_list_push_front(&head, &c);
    t_list *last = ft_list_last(head);
    printf("%d\n", *(int *)last->data); // 42
    return 0;
}
