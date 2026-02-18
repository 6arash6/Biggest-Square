/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		**matrix;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

int		ft_strlen(char *str);
char	*ft_realloc(char *ptr, int old_size, int new_size);
int		ft_atoi(char *str);
int		ft_isnumber(char c);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
char	*ft_get_line(int fd);
int		ft_parse_header(t_map *map, char *line);
int		ft_fill_matrix(t_map *map, int fd);
int		ft_get_matrix(t_map *map, char *filename);
int		ft_get_matrix_from_stdin(t_map *map);
void	ft_process_map(t_map *map);
void	ft_mark_square(t_map *map, int *max_info);
void	ft_print_map(t_map *map);
void	ft_free_map(t_map *map);

#endif
