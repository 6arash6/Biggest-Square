#include <stdio.h>
int ft_any(char **tab, int(*f)(char*));
int is_a(char *s) { return s[0] == 'a'; }
int main(void) {
    char *arr[] = {"bcd", "abc", "xyz", NULL};
    printf("%d\n", ft_any(arr, is_a)); // Output: 1
    return 0;
}
