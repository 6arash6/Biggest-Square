#include <stdio.h>
int ft_strcmp(const char *s1, const char *s2);
int main(void) {
    printf("%d\n", ft_strcmp("Piscine", "Piscine")); // 0
    printf("%d\n", ft_strcmp("Piscine", "42")); // >0
    printf("%d\n", ft_strcmp("42", "Piscine")); // <0
    return 0;
}
