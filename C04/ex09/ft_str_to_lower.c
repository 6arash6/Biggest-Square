// Implement ft_str_to_lower according to 42 Piscine C04 standard
char *ft_str_to_lower(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return str;
}
