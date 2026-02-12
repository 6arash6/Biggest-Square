#include <stdio.h>
#include <stdlib.h>
int *ft_map(int *tab, int length, int(*f)(int));
int square(int n) { return n * n; }
int main(void) {
    int arr[] = {1, 2, 3, 4};
    int *result = ft_map(arr, 4, square);
    for (int i = 0; i < 4; i++)
        printf("%d ", result[i]);
    printf("\n");
    free(result);
    return 0;
}
