// Implement ft_iterative_factorial according to 42 Piscine C05 standard
int ft_iterative_factorial(int nb)
{
    int result = 1;
    if (nb < 0)
        return 0;
    while (nb > 0)
        result *= nb--;
    return result;
}
