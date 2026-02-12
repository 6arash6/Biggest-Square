// Implement ft_strlen according to 42 Piscine C04 standard
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
