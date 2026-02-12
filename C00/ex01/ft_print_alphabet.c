/*
** ex01 - ft_print_alphabet.c
** Displays the alphabet in lowercase, ascending order.
*/
#include <unistd.h>

void ft_print_alphabet(void)
{
    char c = 'a';
    while (c <= 'z')
        write(1, &c++, 1);
}
