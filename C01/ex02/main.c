void ft_ultimate_ft(int *********nbr);
#include <stdio.h>
int main(void) {
    int x = 0;
    int *p1 = &x, **p2 = &p1, ***p3 = &p2, ****p4 = &p3, *****p5 = &p4, ******p6 = &p5, *******p7 = &p6, ********p8 = &p7, *********p9 = &p8;
    ft_ultimate_ft(p9);
    printf("%d\n", x);
    return 0;
}
