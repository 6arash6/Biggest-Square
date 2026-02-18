/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_mark_square(t_map *map, int *max_info)
{
	int	start_row;
	int	start_col;
	int	i;
	int	j;

	start_row = max_info[1] - max_info[0] + 1;
	start_col = max_info[2] - max_info[0] + 1;
	i = start_row;
	while (i <= max_info[1])
	{
		j = start_col;
		while (j <= max_info[2])
		{
			map->matrix[i][j] = 2;
			j++;
		}
		i++;
	}
}
