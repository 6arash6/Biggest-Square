/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-pointer-assignment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** CHANGING VALUES THROUGH POINTERS
**
** You can modify the original variable using a pointer!
** *ptr = new_value changes the value at the address
**
** Key visualization points:
** 1. x starts at 10
** 2. ptr points to x
** 3. *ptr = 99 changes x to 99
** 4. Notice: x is now 99 (changed through pointer!)
** 5. y = *ptr assigns 99 to y
*/

int	main(void)
{
	int	x;
	int	*ptr;
	int	y;

	x = 10;
	ptr = &x;
	*ptr = 99;
	y = *ptr;
	(void)y;
	return (0);
}
