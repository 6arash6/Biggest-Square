#include <stdio.h>
int ft_min(int *arr, int size);

int main(void)
{
    int arr[] = {1, 2, 3, 4};
    printf("%d\n", ft_min(arr, 4)); // 1
    int arr2[] = {-1, -2, -3};
    printf("%d\n", ft_min(arr2, 3)); // -3
    return 0;
}
