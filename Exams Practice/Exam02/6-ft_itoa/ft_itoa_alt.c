#include <stdlib.h>

char *ft_itoa(int n)
{
    int tmp = n, len = (n <= 0), i;
    unsigned int num;
    char *s;

    while (tmp) { len++; tmp /= 10; }
    s = malloc(len + 1);
    if (!s) return NULL;
    s[len] = 0;
    if (n == 0) s[0] = '0';
    if (n < 0) s[0] = '-';
    num = (n < 0) ? -(unsigned int)n : n; // Use unsigned for INT_MIN
    i = len - 1;
    while (num)
    {
        s[i--] = '0' + (num % 10);
        num /= 10;
    }
    return s;