#include "bsq.h"

t_map    *ft_create_map(char *filename)
{
    t_map    *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->matrix = NULL;
    map->rows = 0;
    map->cols = 0;
    if (!ft_get_matrix(map, filename))
    {
        free(map);
        return (NULL);
    }
    return (map);
}

t_map    *ft_create_map_from_stdin(void)
{
    t_map    *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->matrix = NULL;
    map->rows = 0;
    map->cols = 0;
    if (!ft_get_matrix_from_stdin(map))
    {
        free(map);
        return (NULL);
    }
    return (map);
}

void    ft_free_map(t_map *map)
{
    int    i;

    if (!map)
        return ;
    if (map->matrix)
    {
        i = 0;
        while (i < map->rows)
        {
            if (map->matrix[i])
                free(map->matrix[i]);
            i++;
        }
        free(map->matrix);
    }
    free(map);
}
