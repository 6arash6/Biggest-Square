/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-function-pointers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** FUNCTION POINTERS
**
** You can store function addresses in pointers!
** Allows choosing which function to call at runtime
**
** Syntax: return_type (*ptr_name)(param_types)
**
** Key visualization points:
** 1. add and multiply are functions
** 2. operation pointer can point to either
** 3. operation = &add (point to add)
** 4. result1 = operation(5, 3) calls add
** 5. operation = &multiply (point to multiply)
** 6. result2 = operation(5, 3) calls multiply
*/

int	add(int a, int b)
{
	return (a + b);
}

int	multiply(int a, int b)
{
	return (a * b);
}

int	main(void)
{
	int	(*operation)(int, int);
	int	result1;
	int	result2;

	operation = &add;
	result1 = operation(5, 3);
	operation = &multiply;
	result2 = operation(5, 3);
	(void)result1;
	(void)result2;
	return (0);
}
