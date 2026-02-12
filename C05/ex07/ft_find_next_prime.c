// Implement ft_find_next_prime according to 42 Piscine C05 standard
int ft_is_prime(int nb);

int ft_find_next_prime(int nb)
{
    while (!ft_is_prime(nb))
        nb++;
    return nb;
}
