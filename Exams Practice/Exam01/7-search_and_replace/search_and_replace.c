/* ************************************************************************** */
/*                                                                            */
/* search_and_replace - Find and replace character in string                 */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;

	// Check for exactly 3 arguments
	// Also verify that search and replace are single characters
	if (ac == 4 && !av[2][1] && !av[3][1])
	{
		i = 0;
		while (av[1][i])
		{
			// If current char matches search char, write replace char
			if (av[1][i] == av[2][0])
				write(1, &av[3][0], 1);
			// Otherwise write the original char
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* 
 * Important validation:
 * 
 * 1. ac == 4: Must have exactly 3 arguments (program name doesn't count)
 * 
 * 2. !av[2][1] and !av[3][1]: Ensures search and replace are single chars
 *    - av[2][0] is the first character
 *    - av[2][1] should be '\0' for a single character string
 *    - If av[2][1] is not '\0', it means string has more than 1 char
 *    - !av[2][1] is true when av[2][1] == '\0'
 * 
 * Example with "Papache est un sabre" "a" "o":
 * - av[1] = "Papache est un sabre"
 * - av[2] = "a" (search)
 * - av[3] = "o" (replace)
 * 
 * Process each character:
 * P → not 'a' → write 'P'
 * a → equals 'a' → write 'o'
 * p → not 'a' → write 'p'
 * a → equals 'a' → write 'o'
 * ...
 * Output: "Popoche est un sobre"
 * 
 * Edge cases:
 * 
 * 1. Search char not in string:
 *    ./search_and_replace "zaz" "r" "u"
 *    Output: "zaz" (unchanged)
 * 
 * 2. Wrong number of arguments:
 *    ./search_and_replace "zaz" "art" "zul"
 *    - av[2][1] is 'r' (not '\0')
 *    - Condition fails, only prints newline
 * 
 * 3. Too many arguments:
 *    ./search_and_replace "jacob" "a" "b" "c" "e"
 *    - ac == 6, not 4
 *    - Condition fails, only prints newline
 * 
 * Why this exercise is useful:
 * - String manipulation
 * - Argument validation
 * - Character comparison
 * - Understanding string termination ('\0')
 */
