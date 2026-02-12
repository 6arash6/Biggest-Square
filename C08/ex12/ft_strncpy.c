// Implement ft_strncpy according to 42 Piscine C08 standard
char *ft_strncpy(char *dest, const char *src, unsigned int n)
{
    unsigned int i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
