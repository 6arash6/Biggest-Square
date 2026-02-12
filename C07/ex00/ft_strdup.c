// Implement ft_strdup according to 42 Piscine C07 standard
#include <stdlib.h>

char *ft_strdup(const char *src)
{
    int len = 0;
    while (src[len])
        len++;
    char *dup = (char *)malloc(len + 1);
    if (!dup)
        return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}
