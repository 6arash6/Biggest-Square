// Implement ft_strrev according to 42 Piscine C08 standard
int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_strrev(char *str)
{
    int len = ft_strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
    return str;
}
