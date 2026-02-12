// Implement ft_strstr according to 42 Piscine C08 standard
char *ft_strstr(const char *haystack, const char *needle)
{
    if (!*needle)
        return (char *)haystack;
    for (int i = 0; haystack[i]; i++) {
        int j = 0;
        while (needle[j] && haystack[i + j] == needle[j])
            j++;
        if (!needle[j])
            return (char *)&haystack[i];
    }
    return 0;
}
