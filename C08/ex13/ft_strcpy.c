// Implement ft_strcpy according to 42 Piscine C08 standard
char *ft_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
