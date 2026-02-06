/* ************************************************************************** */
/*                                                                            */
/* fizzbuzz - Classic programming interview problem                          */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Helper function to print a number
void	ft_putnbr(int n)
{
	char digit;

	// Handle numbers >= 10 with recursion
	if (n >= 10)
		ft_putnbr(n / 10);
	
	// Convert digit to character and print
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int	main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		// Check for multiples of 15 first (both 3 and 5)
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		
		// Then check for multiples of 3
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		
		// Then check for multiples of 5
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		
		// Otherwise print the number
		else
			ft_putnbr(i);
		
		// Always print newline after each output
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

/* 
 * Important details:
 * 
 * 1. Order of conditions matters!
 *    - Must check % 15 BEFORE % 3 and % 5
 *    - Otherwise 15 would print "fizz" instead of "fizzbuzz"
 * 
 * 2. Why % 15?
 *    - A number divisible by both 3 and 5 is divisible by 15
 *    - 15 is the Least Common Multiple (LCM) of 3 and 5
 * 
 * 3. Alternative condition for fizzbuzz:
 *    if (i % 3 == 0 && i % 5 == 0)
 *    - Both work, but % 15 is more elegant
 * 
 * Output pattern:
 * 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz...
 * 
 * Why this exercise is important:
 * - Tests modulo understanding
 * - Tests conditional logic order
 * - Common interview question
 * - Practice with write() instead of printf()
 * - Practice writing number printing function
 */
