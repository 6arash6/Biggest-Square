int ft_count_if(char **tab, int length, int(*f)(char*)) {
    int count = 0;
    for (int i = 0; i < length; i++)
        if (f(tab[i]))
            count++;
    return count;
}
