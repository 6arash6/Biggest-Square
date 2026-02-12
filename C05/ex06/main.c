#include <stdio.h>
int ft_is_prime(int nb);

int main(void)
{
    printf("%d\n", ft_is_prime(2));    // 1
    printf("%d\n", ft_is_prime(4));    // 0
    printf("%d\n", ft_is_prime(17));   // 1
    printf("%d\n", ft_is_prime(1));    // 0
    printf("%d\n", ft_is_prime(19));   // 1
    return 0;
}
