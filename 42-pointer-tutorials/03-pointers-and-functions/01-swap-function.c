/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-swap-function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** CLASSIC SWAP FUNCTION
**
** Swaps two integers using pointers
** Must pass addresses so we can modify originals
**
** Key visualization points:
** 1. a = 10, b = 20
** 2. Call ft_swap(&a, &b)
** 3. temp = 10 (save *x)
** 4. *x = 20 (x now points to 20)
** 5. *y = 10 (y now points to 10)
** 6. Back in main: a = 20, b = 10 (swapped!)
*/

void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 20;
	ft_swap(&a, &b);
	return (0);
}
