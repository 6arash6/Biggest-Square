/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-modify-array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** MODIFYING ARRAY IN FUNCTION
**
** When you pass an array to a function,
** you're actually passing a pointer!
** 
** Changes inside function affect original array
**
** Key visualization points:
** 1. arr = {1, 2, 3, 4, 5}
** 2. double_values(arr, 5) - pass array
** 3. Inside function: multiply each by 2
** 4. Back in main: arr = {2, 4, 6, 8, 10}
*/

void	double_values(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = arr[i] * 2;
		i++;
	}
}

int	main(void)
{
	int	arr[5];

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	double_values(arr, 5);
	return (0);
}
