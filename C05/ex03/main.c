#include <stdio.h>
int ft_recursive_power(int nb, int power);

int main(void)
{
    printf("%d\n", ft_recursive_power(2, 3));   // 8
    printf("%d\n", ft_recursive_power(5, 0));   // 1
    printf("%d\n", ft_recursive_power(2, -1));  // 0
    printf("%d\n", ft_recursive_power(3, 4));   // 81
    return 0;
}
