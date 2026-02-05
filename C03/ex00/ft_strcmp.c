/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arash Javan Mojarad <ajavan-m@student.42v  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:46:51 by Arash Javan M     #+#    #+#             */
/*   Updated: 2026/02/05 09:51:16 by Arash Javan M    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "word";
	s2 = "Word";
	printf("Or: %d\n", strcmp(s1, s2));
	printf("My: %d\n", ft_strcmp(s1, s2));
}*/