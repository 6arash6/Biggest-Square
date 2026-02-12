#include <stdio.h>
int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
    printf("%d\n", ft_strcmp("abc", "abc")); // 0
    printf("%d\n", ft_strcmp("abc", "abd")); // -1
    printf("%d\n", ft_strcmp("abc", "ab"));  // 'c' - '\0'
    return 0;
}
