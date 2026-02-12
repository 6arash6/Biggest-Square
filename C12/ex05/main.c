#include <stdio.h>
#include "ft_list.h"
t_list *ft_list_push_strs(int size, char **strs);
int main(void) {
    char *arr[] = {"a", "b", "c"};
    t_list *head = ft_list_push_strs(3, arr);
    for (t_list *cur = head; cur; cur = cur->next)
        printf("%s ", (char *)cur->data);
    printf("\n");
    return 0;
}
