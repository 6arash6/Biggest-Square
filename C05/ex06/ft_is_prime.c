// Implement ft_is_prime according to 42 Piscine C05 standard
int ft_is_prime(int nb)
{
    int i;
    if (nb <= 1)
        return 0;
    i = 2;
    while (i * i <= nb) {
        if (nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}
