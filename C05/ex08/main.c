#include <stdio.h>
int ft_ten_queens_puzzle(void);

int main(void)
{
    int count = ft_ten_queens_puzzle();
    printf("Total solutions: %d\n", count);
    return 0;
}
