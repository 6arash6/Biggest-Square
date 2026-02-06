/* ************************************************************************** */
/*                                                                            */
/* SOLUTION 2: Bitwise check (faster than modulo)                            */
/* Uses bitwise AND to check if index is even                                */
/* Very popular in 42 exams - shows advanced understanding                   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;

	i = 0;
	// Check if there is exactly one argument
	if (ac == 2)
	{
		// Loop through the string
		while (av[1][i])
		{
			// Bitwise AND with 1 checks the last bit
			// Even numbers have last bit = 0
			// Odd numbers have last bit = 1
			if ((i & 1) == 0)
				write(1, &av[1][i], 1);
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* 
 * How bitwise check works:
 * 
 * Binary representation:
 * 0 = 0000 → 0 & 1 = 0000 = 0 → even
 * 1 = 0001 → 1 & 1 = 0001 = 1 → odd
 * 2 = 0010 → 2 & 1 = 0000 = 0 → even
 * 3 = 0011 → 3 & 1 = 0001 = 1 → odd
 * 4 = 0100 → 4 & 1 = 0000 = 0 → even
 * 
 * The & 1 operation checks only the last bit!
 * 
 * Why it's faster:
 * - Bitwise operations are CPU-level instructions
 * - Modulo requires division (slower)
 * - In exams both are accepted, but & 1 is "42 style"
 */
