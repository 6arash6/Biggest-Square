#include <stdio.h>
int ft_str_is_alpha(const char *str);

int main(void)
{
    printf("%d\n", ft_str_is_alpha("Hello"));      // 1
    printf("%d\n", ft_str_is_alpha("Hello123"));   // 0
    printf("%d\n", ft_str_is_alpha(""));           // 1
    printf("%d\n", ft_str_is_alpha("42"));         // 0
    printf("%d\n", ft_str_is_alpha("abcDEF"));     // 1
    printf("%d\n", ft_str_is_alpha("abc DEF"));    // 0
    return 0;
}
