// Implement ft_str_is_alpha according to 42 Piscine C04 standard
int ft_str_is_alpha(const char *str)
{
    int i = 0;
    while (str[i]) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
            return 0;
        i++;
    }
    return 1;
}
