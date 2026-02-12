#include <string.h>
void ft_sort_string_tab(char **tab) {
    int i, j;
    for (i = 0; tab[i]; i++) {
        for (j = 0; tab[j + 1]; j++) {
            if (strcmp(tab[j], tab[j + 1]) > 0) {
                char *tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}
