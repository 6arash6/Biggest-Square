#include <stdlib.h>
int *ft_map(int *tab, int length, int(*f)(int)) {
    int *res = malloc(sizeof(int) * length);
    if (!res) return NULL;
    for (int i = 0; i < length; i++)
        res[i] = f(tab[i]);
    return res;
}
