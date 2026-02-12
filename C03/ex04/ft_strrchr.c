// Implement ft_strrchr according to 42 Piscine C03 standard
char *ft_strrchr(const char *s, int c)
{
    int i = 0;
    char *last = 0;
    while (s[i]) {
        if (s[i] == (char)c)
            last = (char *)&s[i];
        i++;
    }
    if (s[i] == (char)c)
        last = (char *)&s[i];
    return last;
}
