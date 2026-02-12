#include "ft_list.h"
void ft_list_reverse_fun(t_list *begin_list) {
    int size = 0;
    t_list *cur = begin_list;
    while (cur) {
        size++;
        cur = cur->next;
    }
    t_list **arr = (t_list **)malloc(sizeof(t_list *) * size);
    cur = begin_list;
    for (int i = 0; i < size; i++) {
        arr[i] = cur;
        cur = cur->next;
    }
    for (int i = 0; i < size / 2; i++) {
        void *tmp = arr[i]->data;
        arr[i]->data = arr[size - 1 - i]->data;
        arr[size - 1 - i]->data = tmp;
    }
    free(arr);
}
