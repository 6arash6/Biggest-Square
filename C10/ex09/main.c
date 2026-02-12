 #include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int cmp(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    t_list *head = NULL;
    int a = 42, b = 24, c = 7;
    ft_list_push_back(&head, &a);
    ft_list_push_back(&head, &b);
    ft_list_push_back(&head, &c);
    ft_list_sort(&head, cmp);
    printf("%d %d %d\n", *(int *)head->data, *(int *)head->next->data, *(int *)head->next->next->data); // 7 24 42
    return 0;
}
