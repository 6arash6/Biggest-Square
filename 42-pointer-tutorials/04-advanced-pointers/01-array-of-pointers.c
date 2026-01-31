/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-array-of-pointers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42 student <student@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:20:00 by student          #+#    #+#             */
/*   Updated: 2026/01/31 11:20:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ARRAY OF POINTERS
**
** char *arr[] - array where each element is a pointer
** Just like argv in main(int argc, char **argv)!
**
** Each element points to a different string
** This is how command-line arguments work
**
** Key visualization points:
** 1. str1, str2, str3 are separate strings
** 2. strs[0] points to str1
** 3. strs[1] points to str2
** 4. strs[2] points to str3
** 5. strs is like argv!
*/

int	main(void)
{
	char	str1[3];
	char	str2[6];
	char	str3[6];
	char	*strs[3];

	str1[0] = '4';
	str1[1] = '2';
	str1[2] = '\0';
	str2[0] = 'H';
	str2[1] = 'e';
	str2[2] = 'l';
	str2[3] = 'l';
	str2[4] = 'o';
	str2[5] = '\0';
	str3[0] = 'W';
	str3[1] = 'o';
	str3[2] = 'r';
	str3[3] = 'l';
	str3[4] = 'd';
	str3[5] = '\0';
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	(void)strs;
	return (0);
}
