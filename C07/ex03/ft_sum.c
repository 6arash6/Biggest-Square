// Implement ft_sum according to 42 Piscine C07 standard
int ft_sum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}
