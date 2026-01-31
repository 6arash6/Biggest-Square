/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-string-manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** STRING MANIPULATION WITH POINTERS
**
** Strings are char arrays ending with '\0'
** We can use pointers to work with them
**
** This example counts string length
** - Start ptr at beginning
** - Move ptr until we find '\0'
** - Count how many steps (length)
**
** Key visualization points:
** 1. str is array of chars: {'4', '2', '\0'}
** 2. ptr walks through each character
** 3. len increments: 0, 1, 2
** 4. Stops at '\0' (null terminator)
*/

int	main(void)
{
	char	str[3];
	char	*ptr;
	int		len;

	str[0] = '4';
	str[1] = '2';
	str[2] = '\0';
	ptr = str;
	len = 0;
	while (*ptr != '\0')
	{
		len++;
		ptr++;
	}
	return (0);
}
