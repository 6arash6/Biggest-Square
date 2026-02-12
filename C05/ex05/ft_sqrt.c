// Implement ft_sqrt according to 42 Piscine C05 standard
int ft_sqrt(int nb)
{
    int i = 0;
    if (nb < 0)
        return 0;
    while (i * i <= nb) {
        if (i * i == nb)
            return i;
        i++;
    }
    return 0;
}
