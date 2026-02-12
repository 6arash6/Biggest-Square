#include <stdio.h>
int ft_recursive_factorial(int nb);

int main(void)
{
    printf("%d\n", ft_recursive_factorial(5));   // 120
    printf("%d\n", ft_recursive_factorial(0));   // 1
    printf("%d\n", ft_recursive_factorial(-1));  // 0
    printf("%d\n", ft_recursive_factorial(10));  // 3628800
    return 0;
}
