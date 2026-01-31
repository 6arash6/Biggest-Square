/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-array-traversal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** TRAVERSING AN ARRAY WITH POINTERS
**
** Instead of using arr[i], we can use pointer arithmetic
** *ptr gives current element
** ptr++ moves to next element
**
** Key visualization points:
** 1. ptr starts at first element
** 2. Loop: read *ptr (current value)
** 3. Increment ptr (move to next)
** 4. Watch sum accumulate: 1 + 2 + 3 + 4 + 5 = 15
*/

int	main(void)
{
	int	arr[5];
	int	*ptr;
	int	i;
	int	sum;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	ptr = arr;
	sum = 0;
	i = 0;
	while (i < 5)
	{
		sum = sum + *ptr;
		ptr++;
		i++;
	}
	return (0);
}
