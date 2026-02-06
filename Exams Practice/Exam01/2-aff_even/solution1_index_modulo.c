/* ************************************************************************** */
/*                                                                            */
/* SOLUTION 1: Classic with index and modulo                                 */
/* This is the most straightforward solution using array indexing            */
/* and the modulo operator to check if position is even                      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;

	// Check if there is exactly one argument
	if (argc == 2)
	{
		i = 0;
		// Loop through each character in the string
		while (argv[1][i] != '\0')
		{
			// Check if the index is even (0, 2, 4, ...)
			if (i % 2 == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	// Always print a newline at the end
	write(1, "\n", 1);
	return (0);
}

/* 
 * How it works:
 * - Uses i % 2 == 0 to check if position is even
 * - Position 0 → 0 % 2 = 0 → even → print
 * - Position 1 → 1 % 2 = 1 → odd  → skip
 * - Position 2 → 2 % 2 = 0 → even → print
 * 
 * Test cases:
 * ./aff_even "hello"  → prints "hlo"
 * ./aff_even "hi"     → prints "h"
 * ./aff_even ""       → prints nothing (just newline)
 */
