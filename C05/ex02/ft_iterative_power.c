// Implement ft_iterative_power according to 42 Piscine C05 standard
int ft_iterative_power(int nb, int power)
{
    int result = 1;
    if (power < 0)
        return 0;
    while (power-- > 0)
        result *= nb;
    return result;
}
