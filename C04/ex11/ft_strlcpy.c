// Implement ft_strlcpy according to 42 Piscine C04 standard
unsigned int ft_strlcpy(char *dest, const char *src, unsigned int size)
{
    unsigned int i = 0;
    if (size == 0)
        return 0;
    while (src[i] && i < size - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    i = 0;
    while (src[i])
        i++;
    return i;
}
