/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	ft_process_file(char *filename)
{
	t_map	map;

	map.matrix = NULL;
	if (!ft_get_matrix(&map, filename))
		return ;
	ft_process_map(&map);
	ft_print_map(&map);
	ft_free_map(&map);
}

static void	ft_process_stdin(void)
{
	t_map	map;

	map.matrix = NULL;
	if (!ft_get_matrix_from_stdin(&map))
		return ;
	ft_process_map(&map);
	ft_print_map(&map);
	ft_free_map(&map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_process_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_process_file(argv[i]);
			if (i < argc - 1)
				ft_putstr("\n");
			i++;
		}
	}
	return (0);
}
