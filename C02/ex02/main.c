#include <stdio.h>
int ft_str_is_alpha(const char *str);
int main(void) {
    printf("%d\n", ft_str_is_alpha("Piscine")); // 1
    printf("%d\n", ft_str_is_alpha("42Piscine")); // 0
    return 0;
}
