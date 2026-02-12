#include <stdio.h>
int ft_strncmp(const char *s1, const char *s2, unsigned int n);

int main(void)
{
    printf("%d\n", ft_strncmp("abc", "abd", 2)); // 0
    printf("%d\n", ft_strncmp("abc", "abd", 3)); // -1
    printf("%d\n", ft_strncmp("abc", "ab", 3));  // 'c' - '\0'
    return 0;
}
