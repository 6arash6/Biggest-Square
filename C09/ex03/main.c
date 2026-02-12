#include <stdio.h>
int ft_atoi(const char *str);

int main(void)
{
    printf("%d\n", ft_atoi("42")); // 42
    printf("%d\n", ft_atoi("-42")); // -42
    printf("%d\n", ft_atoi("   123")); // 123
    printf("%d\n", ft_atoi("+7")); // 7
    return 0;
}
