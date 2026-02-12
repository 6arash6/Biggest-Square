// Implement ft_str_to_upper according to 42 Piscine C04 standard
char *ft_str_to_upper(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}
