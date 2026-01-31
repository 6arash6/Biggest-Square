/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-pointer-to-pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** POINTER TO POINTER (DOUBLE POINTER)
**
** int *ptr   - pointer to int
** int **pptr - pointer to pointer to int
**
** Used when you need to modify a pointer itself
** Common in: argv, 2D arrays, modify pointer in function
**
** Key visualization points:
** 1. x = 42
** 2. ptr points to x
** 3. pptr points to ptr
** 4. **pptr gets value 42 (follow two arrows!)
*/

int	main(void)
{
	int	x;
	int	*ptr;
	int	**pptr;
	int	value;

	x = 42;
	ptr = &x;
	pptr = &ptr;
	value = **pptr;
	(void)value;
	return (0);
}
