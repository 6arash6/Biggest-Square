// Implement ft_strlcat according to 42 Piscine C08 standard
unsigned int ft_strlen(const char *str)
{
    unsigned int len = 0;
    while (str[len])
        len++;
    return len;
}

unsigned int ft_strlcat(char *dest, const char *src, unsigned int size)
{
    unsigned int d_len = ft_strlen(dest);
    unsigned int s_len = ft_strlen(src);
    unsigned int i = 0;
    if (d_len >= size)
        return size + s_len;
    while (src[i] && d_len + i + 1 < size) {
        dest[d_len + i] = src[i];
        i++;
    }
    if (d_len + i < size)
        dest[d_len + i] = '\0';
    return d_len + s_len;
}
