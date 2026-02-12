#include <stdio.h>
int ft_str_is_uppercase(const char *str);
int main(void) {
    printf("%d\n", ft_str_is_uppercase("PISCINE")); // 1
    printf("%d\n", ft_str_is_uppercase("Piscine")); // 0
    return 0;
}
