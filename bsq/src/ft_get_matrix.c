#include "bsq.h"

static int    ft_is_printable(char c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

int    ft_parse_header(t_map *map, char *line)
{
    int        len;
    int        i;
    long    num;

    if (!line)
        return (0);
    len = ft_strlen(line);
    if (len < 4)
        return (0);
    map->full = line[len - 1];
    map->obstacle = line[len - 2];
    map->empty = line[len - 3];
    if (!ft_is_printable(map->empty) || !ft_is_printable(map->obstacle)
        || !ft_is_printable(map->full))
        return (0);
    if (map->empty == map->obstacle || map->empty == map->full
        || map->obstacle == map->full)
        return (0);
    i = 0;
    while (i < len - 3)
    {
        if (!ft_isnumber(line[i]))
            return (0);
        i++;
    }
    num = 0;
    i = 0;
    while (i < len - 3)
    {
        num = num * 10 + (line[i] - '0');
        if (num > 2147483647)
            return (0);
        i++;
    }
    map->rows = (int)num;
    if (map->rows <= 0)
        return (0);
    return (1);
}

static int    ft_validate_line(t_map *map, char *line, int row_index)
{
    int    col_len;
    int    j;

    if (!line)
        return (0);
    col_len = ft_strlen(line);
    if (col_len == 0)
        return (0);
    if (row_index == 0)
        map->cols = col_len;
    else if (col_len != map->cols)
        return (0);
    j = 0;
    while (j < col_len)
    {
        if (line[j] != map->empty && line[j] != map->obstacle)
            return (0);
        j++;
    }
    return (1);
}

static int    ft_fill_row(t_map *map, char *line, int row)
{
    int    j;

    j = 0;
    while (j < map->cols)
    {
        if (line[j] == map->empty)
            map->matrix[row][j] = 1;
        else
            map->matrix[row][j] = 0;
        j++;
    }
    return (1);
}

int    ft_fill_matrix(t_map *map, int fd)
{
    char    *line;
    int        i;

    map->cols = 0;
    map->matrix = (int **)malloc(sizeof(int *) * map->rows);
    if (!map->matrix)
        return (0);
    i = 0;
    while (i < map->rows)
    {
        map->matrix[i] = NULL;
        i++;
    }
    i = 0;
    while (i < map->rows)
    {
        line = ft_get_line(fd);
        if (!line)
        {
            ft_puterror("map error\n");
            return (0);
        }
        if (!ft_validate_line(map, line, i))
        {
            free(line);
            ft_puterror("map error\n");
            return (0);
        }
        map->matrix[i] = (int *)malloc(sizeof(int) * map->cols);
        if (!map->matrix[i])
        {
            free(line);
            ft_puterror("map error\n");
            return (0);
        }
        ft_fill_row(map, line, i);
        free(line);
        i++;
    }
    return (1);
}

int    ft_get_matrix(t_map *map, char *filename)
{
    int        fd;
    char    *header;
    int        result;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_puterror("map error\n");
        return (0);
    }
    header = ft_get_line(fd);
    if (!header)
    {
        close(fd);
        ft_puterror("map error\n");
        return (0);
    }
    if (!ft_parse_header(map, header))
    {
        free(header);
        close(fd);
        ft_puterror("map error\n");
        return (0);
    }
    free(header);
    result = ft_fill_matrix(map, fd);
    close(fd);
    return (result);
}

int    ft_get_matrix_from_stdin(t_map *map)
{
    char    *header;
    int        result;

    header = ft_get_line(0);
    if (!header)
    {
        ft_puterror("map error\n");
        return (0);
    }
    if (!ft_parse_header(map, header))
    {
        free(header);
        ft_puterror("map error\n");
        return (0);
    }
    free(header);
    result = ft_fill_matrix(map, 0);
    return (result);
}
