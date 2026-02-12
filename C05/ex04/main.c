#include <stdio.h>
int ft_fibonacci(int index);

int main(void)
{
    printf("%d\n", ft_fibonacci(0));   // 0
    printf("%d\n", ft_fibonacci(1));   // 1
    printf("%d\n", ft_fibonacci(5));   // 5
    printf("%d\n", ft_fibonacci(-1));  // -1
    printf("%d\n", ft_fibonacci(10));  // 55
    return 0;
}
