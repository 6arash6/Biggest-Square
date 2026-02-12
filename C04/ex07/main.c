#include <stdio.h>
int ft_str_is_printable(const char *str);

int main(void)
{
    printf("%d\n", ft_str_is_printable("Hello!"));     // 1
    printf("%d\n", ft_str_is_printable("Hello\n"));   // 0
    printf("%d\n", ft_str_is_printable("") );         // 1
    printf("%d\n", ft_str_is_printable("abc123"));     // 1
    printf("%d\n", ft_str_is_printable("abc\t123"));  // 0
    printf("%d\n", ft_str_is_printable(" "));          // 1
    return 0;
}
