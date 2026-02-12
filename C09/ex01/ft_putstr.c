// Implement ft_putstr according to 42 Piscine C09 standard
#include <unistd.h>

void ft_putstr(const char *str)
{
    int i = 0;
    while (str[i]) {
        write(1, &str[i], 1);
        i++;
    }
}
