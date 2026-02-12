#include <stdio.h>
void ft_sort_int_tab(int *tab, int size);

int main(void)
{
    int arr[] = {4, 3, 2, 1};
    ft_sort_int_tab(arr, 4);
    for (int i = 0; i < 4; i++)
        printf("%d ", arr[i]);
    printf("\n");
    int arr2[] = {1, 2, 3, 4};
    ft_sort_int_tab(arr2, 4);
    for (int i = 0; i < 4; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    return 0;
}
