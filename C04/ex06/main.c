#include <stdio.h>
int ft_str_is_uppercase(const char *str);

int main(void)
{
    printf("%d\n", ft_str_is_uppercase("HELLO"));     // 1
    printf("%d\n", ft_str_is_uppercase("Hello"));     // 0
    printf("%d\n", ft_str_is_uppercase("") );         // 1
    printf("%d\n", ft_str_is_uppercase("ABC"));       // 1
    printf("%d\n", ft_str_is_uppercase("ABC123"));    // 0
    printf("%d\n", ft_str_is_uppercase("ABC DEF"));   // 0
    return 0;
}
