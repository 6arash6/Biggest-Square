/*
** ex00 - ft_putchar.c
** Write a function that displays the character passed as a parameter.
** Allowed function: write
*/
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
