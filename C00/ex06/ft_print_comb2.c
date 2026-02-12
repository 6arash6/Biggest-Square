/*
** ex06 - ft_print_comb2.c
** Displays all combinations of two distinct two-digit numbers (00 01 ... 98 99).
*/
#include <unistd.h>

void putnbr2(int n)
{
    char d1 = '0' + n / 10;
    char d2 = '0' + n % 10;
    write(1, &d1, 1);
    write(1, &d2, 1);
}

void ft_print_comb2(void)
{
    int i = 0;
    while (i <= 98)
    {
        int j = i + 1;
        while (j <= 99)
        {
            putnbr2(i);
            write(1, " ", 1);
            putnbr2(j);
            if (!(i == 98 && j == 99))
                write(1, ", ", 2);
            j++;
        }
        i++;
    }
}
