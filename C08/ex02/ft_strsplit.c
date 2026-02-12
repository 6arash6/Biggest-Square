// Implement ft_strsplit according to 42 Piscine C08 standard
#include <stdlib.h>

int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int count_words(const char *str, char sep)
{
    int count = 0, i = 0;
    while (str[i]) {
        while (str[i] == sep)
            i++;
        if (str[i]) {
            count++;
            while (str[i] && str[i] != sep)
                i++;
        }
    }
    return count;
}

char **ft_strsplit(const char *str, char sep)
{
    int words = count_words(str, sep);
    char **arr = (char **)malloc((words + 1) * sizeof(char *));
    if (!arr)
        return NULL;
    int i = 0, w = 0;
    while (str[i]) {
        while (str[i] == sep)
            i++;
        if (str[i]) {
            int start = i;
            while (str[i] && str[i] != sep)
                i++;
            int len = i - start;
            arr[w] = (char *)malloc(len + 1);
            for (int j = 0; j < len; j++)
                arr[w][j] = str[start + j];
            arr[w][len] = '\0';
            w++;
        }
    }
    arr[w] = NULL;
    return arr;
}
