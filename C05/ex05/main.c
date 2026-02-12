#include <stdio.h>
int ft_sqrt(int nb);

int main(void)
{
    printf("%d\n", ft_sqrt(9));    // 3
    printf("%d\n", ft_sqrt(16));   // 4
    printf("%d\n", ft_sqrt(10));   // 0
    printf("%d\n", ft_sqrt(-1));   // 0
    printf("%d\n", ft_sqrt(25));   // 5
    return 0;
}
