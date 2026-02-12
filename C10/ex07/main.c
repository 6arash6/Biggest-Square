#include <stdio.h>
#include <stdlib.h>
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *));
t_list *ft_list_push_back(t_list **begin_list, void *data);

int cmp(void *a, void *b) {
    return (*(int *)a != *(int *)b);
}

int main(void)
{
    t_list *head = NULL;
    int a = 42, b = 24, c = 42;
    ft_list_push_back(&head, &a);
    ft_list_push_back(&head, &b);
    ft_list_push_back(&head, &c);
    ft_list_remove_if(&head, &a, cmp);
    printf("%d\n", *(int *)head->data); // 24
    return 0;
}
