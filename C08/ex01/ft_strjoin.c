// Implement ft_strjoin according to 42 Piscine C08 standard
#include <stdlib.h>

int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_strjoin(const char *s1, const char *s2)
{
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    char *res = (char *)malloc(len1 + len2 + 1);
    if (!res)
        return NULL;
    for (int i = 0; i < len1; i++)
        res[i] = s1[i];
    for (int i = 0; i < len2; i++)
        res[len1 + i] = s2[i];
    res[len1 + len2] = '\0';
    return res;
}
