#include <stdlib.h>

int count_words(char *str, char sep)
{
    int count = 0, in_word = 0;
    while (*str)
    {
        if (*str != sep && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*str == sep)
            in_word = 0;
        str++;
    }
    return count;
}

char *word_dup(char *str, char sep)
{
    int len = 0;
    while (str[len] && str[len] != sep)
        len++;
    char *word = malloc(len + 1);
    if (!word) return NULL;
    int i = 0;
    while (i < len)
    {
        word[i] = str[i];
        i++;
    }
    word[len] = 0;
    return word;
}

void free_split(char **arr, int count)
{
    int i = 0;
    while (i < count)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

char **ft_split(char *str, char sep)
{
    int words = count_words(str, sep);
    int i = 0;
    char **arr = malloc((words + 1) * sizeof(char *));
    if (!arr) return NULL;
    while (*str)
    {
        if (*str != sep)
        {
            arr[i] = word_dup(str, sep);
            if (!arr[i])
            {
                free_split(arr, i);
                return NULL;
            }
            i++;
            while (*str && *str != sep)
                str++;
        }
        else
            str++;
    }
    arr[i] = NULL;
    return arr;
}