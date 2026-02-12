#include <stdio.h>
#include <stdlib.h>
char **ft_strsplit(const char *str, char sep);

int main(void)
{
    char **arr = ft_strsplit("a,b,c", ',');
    for (int i = 0; arr[i]; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);
    char **arr2 = ft_strsplit("", ',');
    printf("%p\n", (void *)arr2[0]); // NULL
    free(arr2);
    return 0;
}
