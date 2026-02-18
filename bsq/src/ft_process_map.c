#include "bsq.h"

int    ft_min(int a, int b, int c)
{
    int    min;

    min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return (min);
}

void    ft_find_largest_square(t_map *map, t_square *sq)
{
    int    **dp;
    int    i;
    int    j;
    int    max_size;

    dp = (int **)malloc(sizeof(int *) * map->rows);
    if (!dp)
        return ;
    i = 0;
    while (i < map->rows)
    {
        dp[i] = (int *)malloc(sizeof(int) * map->cols);
        if (!dp[i])
            return ;
        i++;
    }
    sq->size = 0;
    sq->row = 0;
    sq->col = 0;
    max_size = 0;
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            if (i == 0 || j == 0)
                dp[i][j] = map->matrix[i][j];
            else if (map->matrix[i][j] == 1)
                dp[i][j] = ft_min(dp[i - 1][j], dp[i][j - 1],
                        dp[i - 1][j - 1]) + 1;
            else
                dp[i][j] = 0;
            if (dp[i][j] > max_size)
            {
                max_size = dp[i][j];
                sq->size = max_size;
                sq->row = i - max_size + 1;
                sq->col = j - max_size + 1;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < map->rows)
    {
        free(dp[i]);
        i++;
    }
    free(dp);
}

void    ft_draw_square(t_map *map, t_square *sq)
{
    int    i;
    int    j;

    i = sq->row;
    while (i < sq->row + sq->size)
    {
        j = sq->col;
        while (j < sq->col + sq->size)
        {
            map->matrix[i][j] = 2;
            j++;
        }
        i++;
    }
}

void    ft_print_map(t_map *map)
{
    int    i;
    int    j;

    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            if (map->matrix[i][j] == 0)
                ft_putchar(map->obstacle);
            else if (map->matrix[i][j] == 1)
                ft_putchar(map->empty);
            else
                ft_putchar(map->full);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

void    ft_process_map(t_map *map)
{
    t_square    sq;

    if (!map || !map->matrix)
    {
        ft_puterror("map error\n");
        return ;
    }
    ft_find_largest_square(map, &sq);
    ft_draw_square(map, &sq);
    ft_print_map(map);
}
