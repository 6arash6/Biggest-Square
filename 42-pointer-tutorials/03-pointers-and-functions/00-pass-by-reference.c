/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-pass-by-reference.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** PASS BY REFERENCE
**
** Pass by value: function gets a COPY
** Pass by reference: function gets the ADDRESS
**
** With pointers, we can modify the original variable!
**
** Key visualization points:
** 1. x starts at 5
** 2. increment(&x) passes address of x
** 3. Inside function: *num = 6 changes x
** 4. Back in main: x is now 6!
*/

void	increment(int *num)
{
	*num = *num + 1;
}

int	main(void)
{
	int	x;

	x = 5;
	increment(&x);
	return (0);
}
