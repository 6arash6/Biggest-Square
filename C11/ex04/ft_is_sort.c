int ft_is_sort(int *tab, int length, int(*f)(int, int)) {
    int sorted = 1;
    for (int i = 0; i < length - 1; i++) {
        if (f(tab[i], tab[i + 1]) > 0)
            sorted = 0;
    }
    return sorted;
}
