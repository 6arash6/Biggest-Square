#include <stdio.h>
#include <string.h>
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
int cmp(char *a, char *b) { return strcmp(a, b); }
int main(void) {
    char *arr[] = {"bcd", "abc", "acd", NULL};
    ft_advanced_sort_string_tab(arr, cmp);
    for (int i = 0; arr[i]; i++)
        printf("%s ", arr[i]);
    printf("\n");
    return 0;
}
