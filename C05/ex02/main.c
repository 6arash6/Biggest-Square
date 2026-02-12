#include <stdio.h>
int ft_iterative_power(int nb, int power);

int main(void)
{
    printf("%d\n", ft_iterative_power(2, 3));   // 8
    printf("%d\n", ft_iterative_power(5, 0));   // 1
    printf("%d\n", ft_iterative_power(2, -1));  // 0
    printf("%d\n", ft_iterative_power(3, 4));   // 81
    return 0;
}
