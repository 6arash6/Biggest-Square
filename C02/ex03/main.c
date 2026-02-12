#include <stdio.h>
int ft_str_is_numeric(const char *str);
int main(void) {
    printf("%d\n", ft_str_is_numeric("123456")); // 1
    printf("%d\n", ft_str_is_numeric("42Piscine")); // 0
    return 0;
}
