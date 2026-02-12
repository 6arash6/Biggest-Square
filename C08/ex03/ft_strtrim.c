// Implement ft_strtrim according to 42 Piscine C08 standard
#include <stdlib.h>

int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_strtrim(const char *str)
{
    int start = 0, end = ft_strlen(str) - 1;
    while (str[start] && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
        start++;
    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
        end--;
    int len = end - start + 1;
    char *trim = (char *)malloc(len + 1);
    if (!trim)
        return NULL;
    for (int i = 0; i < len; i++)
        trim[i] = str[start + i];
    trim[len] = '\0';
    return trim;
}
