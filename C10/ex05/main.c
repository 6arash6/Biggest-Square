#include <stdio.h>
#include <stdlib.h>
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
t_list *ft_list_push_back(t_list **begin_list, void *data);

int main(void)
{
    t_list *head = NULL;
    int a = 42, b = 24, c = 7;
    ft_list_push_back(&head, &a);
    ft_list_push_back(&head, &b);
    ft_list_push_back(&head, &c);
    t_list *node = ft_list_at(head, 1);
    printf("%d\n", *(int *)node->data); // 24
    return 0;
}
