#include <stdio.h>

int ft_atoi(const char *str); // your implementation

int main(void)
{
    printf("%d\n", ft_atoi("42"));         // 42
    printf("%d\n", ft_atoi("   -123"));    // -123
    printf("%d\n", ft_atoi("+7"));         // 7
    printf("%d\n", ft_atoi("0"));          // 0
    printf("%d\n", ft_atoi("  2147483647"));// 2147483647
    printf("%d\n", ft_atoi("  -2147483648"));// -2147483648
    printf("%d\n", ft_atoi("  42abc"));    // 42
    printf("%d\n", ft_atoi("abc42"));      // 0
    return 0;
}