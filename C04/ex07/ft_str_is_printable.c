// Implement ft_str_is_printable according to 42 Piscine C04 standard
int ft_str_is_printable(const char *str)
{
    int i = 0;
    while (str[i]) {
        if (!(str[i] >= 32 && str[i] <= 126))
            return 0;
        i++;
    }
    return 1;
}
