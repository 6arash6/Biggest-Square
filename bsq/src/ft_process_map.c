/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

static void	ft_update_max(int **dp, int i, int j, int *max_info)
{
	if (dp[i][j] > max_info[0])
	{
		max_info[0] = dp[i][j];
		max_info[1] = i;
		max_info[2] = j;
	}
}

static void	ft_process_dp(t_map *map, int **dp, int *max_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->matrix[i][j] == 1)
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = ft_min(dp[i - 1][j], dp[i][j - 1],
							dp[i - 1][j - 1]) + 1;
				ft_update_max(dp, i, j, max_info);
			}
			else
				dp[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_process_map(t_map *map)
{
	int	**dp;
	int	max_info[3];
	int	i;

	max_info[0] = 0;
	max_info[1] = 0;
	max_info[2] = 0;
	dp = (int **)malloc(sizeof(int *) * map->rows);
	if (!dp)
		return ;
	i = 0;
	while (i < map->rows)
	{
		dp[i] = (int *)malloc(sizeof(int) * map->cols);
		i++;
	}
	ft_process_dp(map, dp, max_info);
	ft_mark_square(map, max_info);
	i = 0;
	while (i < map->rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
