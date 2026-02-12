/*
** ex02 - ft_swap.c
** Swap the values of two integers.
*/
void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
