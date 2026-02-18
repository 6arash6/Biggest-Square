/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_map(t_map *map)
{
	int	i;

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
}
