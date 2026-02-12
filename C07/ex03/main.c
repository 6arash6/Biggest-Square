#include <stdio.h>
int ft_sum(int *arr, int size);

int main(void)
{
    int arr[] = {1, 2, 3, 4};
    printf("%d\n", ft_sum(arr, 4)); // 10
    int arr2[] = {0, 0, 0};
    printf("%d\n", ft_sum(arr2, 3)); // 0
    return 0;
}
