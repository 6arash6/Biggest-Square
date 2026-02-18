/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_get_line(int fd)
{
	char	*line;
	char	buffer;
	int		bytes_read;
	int		size;

	line = NULL;
	size = 0;
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0 && buffer != '\n')
	{
		line = ft_realloc(line, size, size + 2);
		if (!line)
			return (NULL);
		line[size] = buffer;
		line[size + 1] = '\0';
		size++;
		bytes_read = read(fd, &buffer, 1);
	}
	if (size == 0 && bytes_read <= 0)
		return (NULL);
	return (line);
}
