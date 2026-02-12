#include <stdio.h>
int ft_strncmp(const char *s1, const char *s2, unsigned int n);
int main(void) {
    printf("%d\n", ft_strncmp("Piscine", "Piscine", 4)); // 0
    printf("%d\n", ft_strncmp("Piscine", "42", 2)); // >0
    printf("%d\n", ft_strncmp("42", "Piscine", 2)); // <0
    return 0;
}
