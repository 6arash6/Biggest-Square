#include <stdio.h>
int ft_str_is_numeric(const char *str);

int main(void)
{
    printf("%d\n", ft_str_is_numeric("12345"));     // 1
    printf("%d\n", ft_str_is_numeric("123abc"));    // 0
    printf("%d\n", ft_str_is_numeric("") );         // 1
    printf("%d\n", ft_str_is_numeric("42"));        // 1
    printf("%d\n", ft_str_is_numeric("abc123"));    // 0
    printf("%d\n", ft_str_is_numeric("123 456"));   // 0
    return 0;
}
