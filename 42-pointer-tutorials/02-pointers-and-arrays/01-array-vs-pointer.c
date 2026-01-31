/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-array-vs-pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ARRAY vs POINTER NOTATION
**
** Four equivalent ways to access array elements:
** 1. arr[i]       - Array subscript notation
** 2. *(arr + i)   - Pointer arithmetic
** 3. ptr[i]       - Pointer subscript notation
** 4. *(ptr + i)   - Pointer arithmetic with ptr
**
** All four get the SAME value!
**
** Key visualization points:
** 1. All variables get value 30 (arr[2])
** 2. Different syntax, same result
*/

int	main(void)
{
	int	arr[5];
	int	*ptr;
	int	v1;
	int	v2;
	int	v3;
	int	v4;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	ptr = arr;
	v1 = arr[2];
	v2 = *(arr + 2);
	v3 = ptr[2];
	v4 = *(ptr + 2);
	(void)v1;
	(void)v2;
	(void)v3;
	(void)v4;
	return (0);
}
