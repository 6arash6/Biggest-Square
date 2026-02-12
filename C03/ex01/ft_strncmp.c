// Implement ft_strncmp according to 42 Piscine C03 standard
int ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
    unsigned int i = 0;
    while (i < n && (s1[i] || s2[i])) {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        i++;
    }
    return 0;
}
