/*
** ex04 - ft_ultimate_div_mod.c
** Divide and modulo two integers, store results in the addresses pointed to by pointers.
*/
void ft_ultimate_div_mod(int *a, int *b)
{
    int div = *a / *b;
    int mod = *a % *b;
    *a = div;
    *b = mod;
}
