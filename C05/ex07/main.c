#include <stdio.h>
int ft_find_next_prime(int nb);

int main(void)
{
    printf("%d\n", ft_find_next_prime(10));   // 11
    printf("%d\n", ft_find_next_prime(17));   // 17
    printf("%d\n", ft_find_next_prime(20));   // 23
    printf("%d\n", ft_find_next_prime(1));    // 2
    printf("%d\n", ft_find_next_prime(19));   // 19
    return 0;
}
