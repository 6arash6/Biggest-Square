/* ************************************************************************** */
/*                                                                            */
/* alpha_mirror - Mirror alphabet positions                                  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	char c;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			c = av[1][i];
			
			// Mirror lowercase letters
			if (c >= 'a' && c <= 'z')
			{
				// Formula: mirror = 'z' - (char - 'a')
				// a → 'z' - 0 = z
				// b → 'z' - 1 = y  
				// c → 'z' - 2 = x
				c = 'z' - (c - 'a');
			}
			// Mirror uppercase letters
			else if (c >= 'A' && c <= 'Z')
			{
				// Formula: mirror = 'Z' - (char - 'A')
				// A → 'Z' - 0 = Z
				// B → 'Z' - 1 = Y
				// C → 'Z' - 2 = X
				c = 'Z' - (c - 'A');
			}
			// Non-alphabetic characters remain unchanged
			
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* 
 * How the mirror formula works:
 * 
 * Alphabet positions:
 * a=0  b=1  c=2  ... x=23 y=24 z=25
 * z=0  y=1  x=2  ... c=23 b=24 a=25 (mirrored)
 * 
 * For 'a' (position 0):
 * - 'a' - 'a' = 0
 * - 'z' - 0 = 'z'
 * 
 * For 'c' (position 2):
 * - 'c' - 'a' = 2
 * - 'z' - 2 = 'x'
 * 
 * For 'z' (position 25):
 * - 'z' - 'a' = 25
 * - 'z' - 25 = 'a'
 * 
 * Example with "abc":
 * - 'a' → position 0 → mirror = 'z' - 0 = 'z'
 * - 'b' → position 1 → mirror = 'z' - 1 = 'y'
 * - 'c' → position 2 → mirror = 'z' - 2 = 'x'
 * Output: "zyx"
 * 
 * Example with "My horse is Amazing.":
 * - 'M' → 'N' (13th letter mirrors to 13th from end)
 * - 'y' → 'b'
 * - ' ' → ' ' (space unchanged)
 * - 'h' → 's'
 * - and so on...
 * Output: "Nb slihv rh Znzarmt."
 * 
 * This is like ROT13 but instead of rotating, we flip/mirror!
 */
