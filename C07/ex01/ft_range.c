// Implement ft_range according to 42 Piscine C07 standard
#include <stdlib.h>

int *ft_range(int min, int max)
{
    if (min >= max)
        return NULL;
    int *arr = (int *)malloc((max - min) * sizeof(int));
    if (!arr)
        return NULL;
    for (int i = 0; i < max - min; i++)
        arr[i] = min + i;
    return arr;
}
