// Implement ft_create_array according to 42 Piscine C08 standard
#include <stdlib.h>

char *ft_create_array(unsigned int size, char c)
{
    char *arr = (char *)malloc(size + 1);
    if (!arr)
        return NULL;
    for (unsigned int i = 0; i < size; i++)
        arr[i] = c;
    arr[size] = '\0';
    return arr;
}
