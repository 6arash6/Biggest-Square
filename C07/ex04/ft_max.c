// Implement ft_max according to 42 Piscine C07 standard
int ft_max(int *arr, int size)
{
    if (size <= 0)
        return 0;
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
