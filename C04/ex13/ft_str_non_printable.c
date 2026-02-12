// Implement ft_str_non_printable according to 42 Piscine C04 standard
#include <stdio.h>

void ft_str_non_printable(const char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] < 32 || str[i] > 126)
            printf("\\%02x", (unsigned char)str[i]);
        else
            putchar(str[i]);
        i++;
    }
    putchar('\n');
}
