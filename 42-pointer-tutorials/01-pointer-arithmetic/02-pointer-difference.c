/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-pointer-difference.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** POINTER DIFFERENCE
**
** You can subtract two pointers!
** Result = number of elements between them
** 
** Useful for finding:
** - Array length
** - Distance between positions
**
** Key visualization points:
** 1. start points to arr[0]
** 2. end points to arr[4]
** 3. diff = end - start = 4 (4 elements apart)
** 4. Notice: This gives us array size!
*/

int	main(void)
{
	int	arr[5];
	int	*start;
	int	*end;
	int	diff;

	arr[0] = 100;
	arr[1] = 200;
	arr[2] = 300;
	arr[3] = 400;
	arr[4] = 500;
	start = &arr[0];
	end = &arr[4];
	diff = end - start;
	(void)diff;
	return (0);
}
