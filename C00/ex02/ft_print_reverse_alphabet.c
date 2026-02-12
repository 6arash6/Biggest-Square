/*
** ex02 - ft_print_reverse_alphabet.c
** Displays the alphabet in lowercase, descending order.
*/
#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
    char c = 'z';
    while (c >= 'a')
        write(1, &c--, 1);
}
