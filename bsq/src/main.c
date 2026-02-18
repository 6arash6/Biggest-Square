/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student          #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int    main(int argc, char **argv)
{
    t_map    *map;
    int        i;

    if (argc == 1)
    {
        map = ft_create_map_from_stdin();
        if (map)
        {
            ft_process_map(map);
            ft_free_map(map);
        }
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            map = ft_create_map(argv[i]);
            if (map)
            {
                ft_process_map(map);
                ft_free_map(map);
            }
            if (i < argc - 1)
                ft_putchar('\n');
            i++;
        }
    }
    return (0);
}
