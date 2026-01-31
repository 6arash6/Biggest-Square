/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-what-is-pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** WHAT IS A POINTER?
** 
** A pointer is a variable that stores a memory address.
** Think of memory as a big array of boxes, each box has:
** - An address (where it is)
** - A value (what's inside)
**
** Key visualization points in Python Tutor:
** 1. Watch 'x' get value 42
** 2. Watch 'ptr' get the address of x (shown as arrow)
** 3. Notice ptr points to x
*/

int	main(void)
{
	int	x;
	int	*ptr;

	x = 42;
	ptr = &x;
	(void)ptr;
	return (0);
}
