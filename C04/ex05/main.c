#include <stdio.h>
int ft_str_is_lowercase(const char *str);

int main(void)
{
    printf("%d\n", ft_str_is_lowercase("hello"));     // 1
    printf("%d\n", ft_str_is_lowercase("Hello"));     // 0
    printf("%d\n", ft_str_is_lowercase("") );         // 1
    printf("%d\n", ft_str_is_lowercase("abc"));       // 1
    printf("%d\n", ft_str_is_lowercase("abc123"));    // 0
    printf("%d\n", ft_str_is_lowercase("abc def"));   // 0
    return 0;
}
