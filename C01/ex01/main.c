void ft_swap(int *a, int *b);
#include <stdio.h>
int main(void) {
    int x = 1, y = 2;
    ft_swap(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}
