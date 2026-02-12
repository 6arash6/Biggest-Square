// Implement ft_strlcpy according to 42 Piscine C08 standard
unsigned int ft_strlcpy(char *dest, const char *src, unsigned int size)
{
    unsigned int i = 0;
    while (src[i] && i + 1 < size) {
        dest[i] = src[i];
        i++;
    }
    if (size > 0)
        dest[i] = '\0';
    i = 0;
    while (src[i])
        i++;
    return i;
}
