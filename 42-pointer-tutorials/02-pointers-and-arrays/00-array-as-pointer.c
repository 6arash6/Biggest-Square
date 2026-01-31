/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-array-as-pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ARRAY NAME AS POINTER
**
** In C, the array name is a pointer to its first element!
** arr is equivalent to &arr[0]
**
** This is why we can:
** - Assign arr to a pointer
** - Pass arrays to functions (actually passing pointer)
**
** Key visualization points:
** 1. arr and ptr both point to same location
** 2. Both can access array elements
** 3. arr[0] and *ptr are the same value
*/

int	main(void)
{
	int	arr[4];
	int	*ptr;

	arr[0] = 11;
	arr[1] = 22;
	arr[2] = 33;
	arr[3] = 44;
	ptr = arr;
	(void)ptr;
	return (0);
}
