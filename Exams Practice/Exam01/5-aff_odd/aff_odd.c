/* ************************************************************************** */
/*                                                                            */
/* aff_odd - Print characters at odd positions                               */
/* Complement to aff_even - same logic but check for odd instead             */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			// Check if position is ODD (1, 3, 5, 7...)
			// Method 1: Using modulo
			if (i % 2 == 1)
				write(1, &av[1][i], 1);
			
			// Alternative: Using bitwise (commented out)
			// if (i & 1)  // If last bit is 1, it's odd
			//     write(1, &av[1][i], 1);
			
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* 
 * Difference from aff_even:
 * 
 * aff_even: if (i % 2 == 0)  → positions 0, 2, 4, 6...
 * aff_odd:  if (i % 2 == 1)  → positions 1, 3, 5, 7...
 * 
 * Or with bitwise:
 * aff_even: if ((i & 1) == 0) or if (!(i & 1))
 * aff_odd:  if (i & 1)
 * 
 * Example with "hello":
 * Position: 0   1   2   3   4
 * Char:     h   e   l   l   o
 * Odd?:     No  Yes No  Yes No
 * Print:        e       l
 * Output: "el"
 * 
 * Example with "hi":
 * Position: 0   1
 * Char:     h   i
 * Odd?:     No  Yes
 * Print:        i
 * Output: "i"
 * 
 * Example with "a":
 * Position: 0
 * Char:     a
 * Odd?:     No
 * Print:    (nothing)
 * Output: ""
 */
