/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-increment-decrement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** POINTER INCREMENT AND DECREMENT
**
** ptr++ moves pointer to next element (forward)
** ptr-- moves pointer to previous element (backward)
** 
** Important: Pointer moves by sizeof(type) bytes!
** int pointer: moves by 4 bytes
** char pointer: moves by 1 byte
**
** Key visualization points:
** 1. ptr starts at arr[0]
** 2. ptr++ moves to arr[1]
** 3. ptr++ moves to arr[2]
** 4. ptr-- moves back to arr[1]
*/

int	main(void)
{
	int	arr[3];
	int	*ptr;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	ptr = &arr[0];
	ptr++;
	ptr++;
	ptr--;
	return (0);
}
