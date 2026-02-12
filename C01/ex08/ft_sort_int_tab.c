/*
** ex08 - ft_sort_int_tab.c
** Sort an int array in ascending order.
*/
void ft_sort_int_tab(int *tab, int size)
{
    int i, j, temp;
    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - 1 - i)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
