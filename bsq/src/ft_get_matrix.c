/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	read_and_validate_header(int fd, t_map *map, char **header)
{
	*header = ft_get_line(fd);
	if (!*header)
		return (0);
	if (!ft_parse_header(map, *header))
	{
		free(*header);
		return (0);
	}
	return (1);
}

int	ft_get_matrix(t_map *map, char *filename)
{
	int		fd;
	char	*header;
	int		result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror("map error\n");
		return (0);
	}
	if (!read_and_validate_header(fd, map, &header))
	{
		close(fd);
		ft_puterror("map error\n");
		return (0);
	}
	free(header);
	result = ft_fill_matrix(map, fd);
	close(fd);
	return (result);
}

int	ft_get_matrix_from_stdin(t_map *map)
{
	char	*header;
	int		result;

	if (!read_and_validate_header(0, map, &header))
	{
		ft_puterror("map error\n");
		return (0);
	}
	result = ft_fill_matrix(map, 0);
	free(header);
	return (result);
}
