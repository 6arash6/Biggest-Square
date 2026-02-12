// Implement ft_str_is_uppercase according to 42 Piscine C04 standard
int ft_str_is_uppercase(const char *str)
{
    int i = 0;
    while (str[i]) {
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return 0;
        i++;
    }
    return 1;
}
