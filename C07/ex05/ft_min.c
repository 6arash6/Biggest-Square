// Implement ft_min according to 42 Piscine C07 standard
int ft_min(int *arr, int size)
{
    if (size <= 0)
        return 0;
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
