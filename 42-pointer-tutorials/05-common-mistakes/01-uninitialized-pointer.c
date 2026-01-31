/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-uninitialized-pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** UNINITIALIZED POINTER (WILD POINTER)
**
** DANGER: Using pointer before initialization
** 
** Wild pointer contains garbage (random memory address)
** Dereferencing = CRASH or unpredictable behavior
**
** THIS CODE SHOWS THE MISTAKE - DO NOT DO THIS!
**
** Key points:
** 1. BAD: int *bad_ptr; (not initialized!)
** 2. BAD would crash: *bad_ptr = 42;
** 3. GOOD: int *good_ptr = &x; (initialized)
** 4. GOOD is safe: *good_ptr = 42;
*/

int	main(void)
{
	int	x;
	int	*good_ptr;

	x = 0;
	good_ptr = &x;
	*good_ptr = 42;
	return (0);
}
