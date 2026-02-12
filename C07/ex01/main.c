#include <stdio.h>
#include <stdlib.h>
int *ft_range(int min, int max);

int main(void)
{
    int *arr = ft_range(3, 7);
    for (int i = 0; i < 4; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    int *arr2 = ft_range(5, 5);
    printf("%p\n", (void *)arr2); // NULL
    return 0;
}
