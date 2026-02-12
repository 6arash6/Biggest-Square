// Implement ft_strstr according to 42 Piscine C03 standard
char *ft_strstr(const char *haystack, const char *needle)
{
    int i = 0, j;
    if (!needle[0]) return (char *)haystack;
    while (haystack[i]) {
        j = 0;
        while (needle[j] && haystack[i + j] == needle[j])
            j++;
        if (!needle[j])
            return (char *)&haystack[i];
        i++;
    }
    return 0;
}
