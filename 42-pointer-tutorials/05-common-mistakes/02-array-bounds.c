/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-array-bounds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ARRAY BOUNDS CHECKING
**
** DANGER: Accessing outside array bounds
** 
** Array of size 5: valid indices are 0, 1, 2, 3, 4
** Accessing arr[5] or arr[10] = undefined behavior!
**
** Common causes:
** - Off-by-one errors in loops
** - Wrong size calculations
** - Pointer arithmetic gone wrong
**
** Key visualization points:
** 1. arr has 5 elements (0-4)
** 2. Loop correctly stops at i < 5
** 3. Never accesses arr[5] or beyond
*/

int	main(void)
{
	int	arr[5];
	int	i;
	int	sum;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	sum = 0;
	i = 0;
	while (i < 5)
	{
		sum = sum + arr[i];
		i++;
	}
	return (0);
}
