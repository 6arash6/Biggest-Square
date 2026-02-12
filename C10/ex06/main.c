#include <stdio.h>
#include <stdlib.h>
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
void ft_list_reverse(t_list **begin_list);
t_list *ft_list_push_back(t_list **begin_list, void *data);

int main(void)
{
    t_list *head = NULL;
    int a = 42, b = 24, c = 7;
    ft_list_push_back(&head, &a);
    ft_list_push_back(&head, &b);
    ft_list_push_back(&head, &c);
    ft_list_reverse(&head);
    printf("%d %d %d\n", *(int *)head->data, *(int *)head->next->data, *(int *)head->next->next->data); // 7 24 42
    return 0;
}
