#include <stdio.h>
void ft_foreach(int *tab, int length, void(*f)(int));
void print(int n) { printf("%d ", n); }
int main(void) {
    int arr[] = {1, 2, 3, 4};
    ft_foreach(arr, 4, print);
    printf("\n");
    return 0;
}
