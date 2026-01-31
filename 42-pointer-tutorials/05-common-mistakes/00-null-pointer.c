/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-null-pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** NULL POINTER HANDLING
**
** NULL is a special pointer value meaning "points nowhere"
** ALWAYS check for NULL before dereferencing!
**
** Common sources of NULL:
** - malloc failure
** - Function returning NULL on error
** - Explicitly set to NULL
**
** Key visualization points:
** 1. ptr = 0 (NULL in C)
** 2. Check: if (ptr != 0) is false
** 3. Safe: we don't dereference NULL
** 4. x stays 0 (not assigned)
*/

int	main(void)
{
	int	*ptr;
	int	x;

	ptr = 0;
	x = 0;
	if (ptr != 0)
	{
		x = *ptr;
	}
	(void)x;
	return (0);
}
