#include <stdio.h>
int ft_str_is_lowercase(const char *str);
int main(void) {
    printf("%d\n", ft_str_is_lowercase("piscine")); // 1
    printf("%d\n", ft_str_is_lowercase("Piscine")); // 0
    return 0;
}
