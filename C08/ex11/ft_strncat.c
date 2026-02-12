// Implement ft_strncat according to 42 Piscine C08 standard
int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_strncat(char *dest, const char *src, unsigned int n)
{
    int d_len = ft_strlen(dest);
    unsigned int i = 0;
    while (src[i] && i < n) {
        dest[d_len + i] = src[i];
        i++;
    }
    dest[d_len + i] = '\0';
    return dest;
}
