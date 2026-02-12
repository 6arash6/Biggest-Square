#include <stdio.h>
#include <stdlib.h>
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
t_list *ft_list_push_back(t_list **begin_list, void *data);

int main(void)
{
    t_list *head = NULL;
    int a = 42, b = 24;
    ft_list_push_back(&head, &a);
    ft_list_push_back(&head, &b);
    printf("%d %d\n", *(int *)head->data, *(int *)head->next->data); // 42 24
    return 0;
}
