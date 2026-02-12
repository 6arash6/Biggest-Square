// Implement ft_itoa according to 42 Piscine C09 standard
#include <stdlib.h>

int num_len(int n)
{
    int len = (n <= 0) ? 1 : 0;
    while (n) {
        len++;
        n /= 10;
    }
    return len;
}

char *ft_itoa(int n)
{
    int len = num_len(n);
    char *str = (char *)malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    unsigned int num = (n < 0) ? -n : n;
    if (n < 0)
        str[0] = '-';
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '-')
            break;
        str[i] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}
