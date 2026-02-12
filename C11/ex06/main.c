#include <stdio.h>
void ft_sort_string_tab(char **tab);
int main(void) {
    char *arr[] = {"bcd", "abc", "acd", NULL};
    ft_sort_string_tab(arr);
    for (int i = 0; arr[i]; i++)
        printf("%s ", arr[i]);
    printf("\n");
    return 0;
}
