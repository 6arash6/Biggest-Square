/*
** ex08 - ft_print_combn.c
** Displays all unique combinations of n distinct digits in ascending order.
*/
#include <unistd.h>

void print_digits(int *arr, int n)
{
    int i = 0;
    while (i < n)
    {
        write(1, &"0123456789"[arr[i]], 1);
        i++;
    }
}

void ft_print_combn(int n)
{
    int arr[10];
    int i, j;
    i = 0;
    while (i < n)
    {
        arr[i] = i;
        i++;
    }
    while (1)
    {
        print_digits(arr, n);
        i = n - 1;
        while (i >= 0 && arr[i] == 10 - n + i)
            i--;
        if (i < 0)
            break;
        arr[i]++;
        j = i + 1;
        while (j < n)
        {
            arr[j] = arr[j - 1] + 1;
            j++;
        }
        write(1, ", ", 2);
    }
}
