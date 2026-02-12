// Implement ft_str_is_lowercase according to 42 Piscine C02 standard
int ft_str_is_lowercase(const char *str)
{
    int i = 0;
    while (str[i]) {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return 0;
        i++;
    }
    return 1;
}
