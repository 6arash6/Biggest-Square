// Implement ft_putchar according to 42 Piscine C09 standard
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
