/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student          #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096
# define MAX_SIZE 100000

typedef struct s_map
{
    int        **matrix;
    int        rows;
    int        cols;
    char    empty;
    char    obstacle;
    char    full;
}            t_map;

typedef struct s_square
{
    int    row;
    int    col;
    int    size;
}        t_square;

/* Main functions */
int        main(int argc, char **argv);

/* Map creation */
t_map    *ft_create_map(char *filename);
t_map    *ft_create_map_from_stdin(void);
void    ft_free_map(t_map *map);

/* Matrix operations */
int        ft_get_matrix(t_map *map, char *filename);
int        ft_get_matrix_from_stdin(t_map *map);
int        ft_parse_header(t_map *map, char *line);
int        ft_fill_matrix(t_map *map, int fd);

/* Processing */
void    ft_process_map(t_map *map);
void    ft_find_largest_square(t_map *map, t_square *sq);
void    ft_draw_square(t_map *map, t_square *sq);
void    ft_print_map(t_map *map);

/* Utilities */
char    *ft_realloc(char *str, int old_size, int new_size);
int        ft_atoi(char *str);
int        ft_isnumber(char c);
int        ft_strlen(char *str);
void    ft_putstr(char *str);
void    ft_putchar(char c);
void    ft_puterror(char *str);
char    *ft_get_line(int fd);

#endif
