/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

static int	parse_number_part(char *line, int len, int *out_rows)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (i < len - 3)
	{
		num = num * 10 + (line[i] - '0');
		if (num > 2147483647)
			return (0);
		i++;
	}
	*out_rows = (int)num;
	return (1);
}

static int	validate_symbols(t_map *map, char *line, int len)
{
	map->full = line[len - 1];
	map->obstacle = line[len - 2];
	map->empty = line[len - 3];
	if (!ft_is_printable(map->empty) || !ft_is_printable(map->obstacle)
		|| !ft_is_printable(map->full))
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

static int	digits_are_valid(char *line, int len)
{
	int	i;

	i = 0;
	while (i < len - 3)
	{
		if (!ft_isnumber(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_header(t_map *map, char *line)
{
	int	len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len < 4)
		return (0);
	if (!validate_symbols(map, line, len))
		return (0);
	if (!digits_are_valid(line, len))
		return (0);
	if (!parse_number_part(line, len, &map->rows))
		return (0);
	if (map->rows <= 0)
		return (0);
	return (1);
}
