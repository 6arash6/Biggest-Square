#include <stdio.h>
#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max);

int main(void)
{
    int *arr;
    int len = ft_ultimate_range(&arr, 3, 7);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    int *arr2;
    len = ft_ultimate_range(&arr2, 5, 5);
    printf("%p %d\n", (void *)arr2, len); // NULL 0
    return 0;
}
