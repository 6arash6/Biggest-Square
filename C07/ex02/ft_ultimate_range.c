// Implement ft_ultimate_range according to 42 Piscine C07 standard
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    if (min >= max) {
        *range = NULL;
        return 0;
    }
    int len = max - min;
    *range = (int *)malloc(len * sizeof(int));
    if (!*range)
        return -1;
    for (int i = 0; i < len; i++)
        (*range)[i] = min + i;
    return len;
}
