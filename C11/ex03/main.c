#include <stdio.h>
int ft_count_if(char **tab, int length, int(*f)(char*));
int is_a(char *s) { return s[0] == 'a'; }
int main(void) {
    char *arr[] = {"abc", "bcd", "acd"};
    printf("%d\n", ft_count_if(arr, 3, is_a)); // Output: 2
    return 0;
}
