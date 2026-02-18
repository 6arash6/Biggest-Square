/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	alloc_matrix_rows(t_map *map)
{
	int	i;

	map->matrix = (int **)malloc(sizeof(int *) * map->rows);
	if (!map->matrix)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->matrix[i] = NULL;
		i++;
	}
	return (1);
}

static int	ft_validate_line(t_map *map, char *line, int row_index)
{
	int	col_len;
	int	j;

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

static int	process_row(t_map *map, char *line, int row)
{
	int	j;

	if (!line)
		return (0);
	if (!ft_validate_line(map, line, row))
		return (0);
	map->matrix[row] = (int *)malloc(sizeof(int) * map->cols);
	if (!map->matrix[row])
		return (0);
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

int	ft_fill_matrix(t_map *map, int fd)
{
	char	*line;
	int		i;

	map->cols = 0;
	if (!alloc_matrix_rows(map))
		return (0);
	i = 0;
	while (i < map->rows)
	{
		line = ft_get_line(fd);
		if (!line || !process_row(map, line, i))
		{
			if (line)
				free(line);
			ft_puterror("map error\n");
			return (0);
		}
		free(line);
		i++;
	}
	return (1);
}
