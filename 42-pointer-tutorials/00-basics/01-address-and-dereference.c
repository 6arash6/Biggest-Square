/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-address-and-dereference.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ADDRESS (&) and DEREFERENCE (*) OPERATORS
**
** & (address-of): Gets the memory address of a variable
** * (dereference): Gets the value at the address stored in pointer
**
** Key visualization points:
** 1. num = 21
** 2. ptr = &num (ptr now points to num)
** 3. *ptr reads value at address (gets 21)
** 4. value gets 21
** 5. Notice: value and num both have 21
*/

int	main(void)
{
	int	num;
	int	*ptr;
	int	value;

	num = 21;
	ptr = &num;
	value = *ptr;
	(void)value;
	return (0);
}
