#include <stdio.h>
int ft_max(int *arr, int size);

int main(void)
{
    int arr[] = {1, 2, 3, 4};
    printf("%d\n", ft_max(arr, 4)); // 4
    int arr2[] = {-1, -2, -3};
    printf("%d\n", ft_max(arr2, 3)); // -1
    return 0;
}
