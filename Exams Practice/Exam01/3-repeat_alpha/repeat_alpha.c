/* ************************************************************************** */
/*                                                                            */
/* repeat_alpha - Solution with detailed explanations                        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	int i;
	int repeat;
	int j;

	i = 0;
	// Loop through each character in the string
	while (str[i])
	{
		// Check if it's a lowercase letter
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			// Calculate repeat count: 'a' = 1, 'b' = 2, 'c' = 3, etc.
			repeat = str[i] - 'a' + 1;
			
			// Print the character 'repeat' times
			j = 0;
			while (j < repeat)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		// Check if it's an uppercase letter
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			// Calculate repeat count: 'A' = 1, 'B' = 2, 'C' = 3, etc.
			repeat = str[i] - 'A' + 1;
			
			// Print the character 'repeat' times
			j = 0;
			while (j < repeat)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		// If it's not a letter, just print it once
		else
			write(1, &str[i], 1);
		
		i++;
	}
}

int	main(int ac, char **av)
{
	// Only process if exactly one argument
	if (ac == 2)
		repeat_alpha(av[1]);
	
	// Always print newline at the end
	write(1, "\n", 1);
	return (0);
}

/* 
 * How it works:
 * 
 * 1. For each character, check if it's a letter
 * 2. If letter, calculate its position in alphabet:
 *    - 'a' - 'a' = 0, + 1 = 1 → print 1 time
 *    - 'b' - 'a' = 1, + 1 = 2 → print 2 times
 *    - 'c' - 'a' = 2, + 1 = 3 → print 3 times
 *    - 'z' - 'a' = 25, + 1 = 26 → print 26 times
 * 
 * 3. If not a letter, print once (spaces, digits, punctuation)
 * 
 * Example with "abc":
 * - 'a' → position 1 → print 'a' 1 time → "a"
 * - 'b' → position 2 → print 'b' 2 times → "bb"
 * - 'c' → position 3 → print 'c' 3 times → "ccc"
 * Output: "abbccc"
 * 
 * Example with "Alex.":
 * - 'A' → position 1 → "A"
 * - 'l' → position 12 → "llllllllllll"
 * - 'e' → position 5 → "eeeee"
 * - 'x' → position 24 → "xxxxxxxxxxxxxxxxxxxxxxxx"
 * - '.' → not a letter → "."
 * Output: "Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx."
 */
