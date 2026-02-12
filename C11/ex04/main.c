#include <stdio.h>
int ft_is_sort(int *tab, int length, int(*f)(int, int));
int cmp(int a, int b) { return a - b; }
int main(void) {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {4, 3, 2, 1};
    printf("%d\n", ft_is_sort(arr1, 4, cmp)); // Output: 1
    printf("%d\n", ft_is_sort(arr2, 4, cmp)); // Output: 0
    return 0;
}
