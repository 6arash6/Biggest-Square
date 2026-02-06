/* ************************************************************************** */
/*                                                                            */
/* SOLUTION 3: Pointer arithmetic - SAFE VERSION (recommended)               */
/* Uses pointers instead of array indexing                                   */
/* This version properly handles all edge cases                              */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char *str;

	if (ac == 2)
	{
		str = av[1];		// Point to start of string
		
		while (*str)		// While not at '\0'
		{
			write(1, str, 1);	// Print even-position char
			str++;			// Move to odd position
			
			// Check if we're not at end before skipping
			if (*str)
				str++;		// Skip odd-position char
		}
	}
	
	write(1, "\n", 1);
	return (0);
}

/* 
 * How it works step by step with "hello":
 * 
 * Initial: str → 'h' (position 0 - even)
 * Step 1:  write 'h'
 *          str++ → now at 'e' (position 1 - odd)
 *          str++ → now at 'l' (position 2 - even)
 * 
 * Step 2:  write 'l'
 *          str++ → now at 'l' (position 3 - odd)
 *          str++ → now at 'o' (position 4 - even)
 * 
 * Step 3:  write 'o'
 *          str++ → now at '\0' (end)
 *          if (*str) → false, don't increment again
 * 
 * Step 4:  while (*str) → false, exit loop
 * 
 * Output: "hlo"
 * 
 * Why the if (*str) check is CRITICAL:
 * - Without it, str++ would go past '\0' 
 * - This could cause segfault or undefined behavior
 * - Always check before advancing pointer!
 * 
 * Example with "hi" (length 2):
 * str → 'h' → write 'h' → str++ → 'i' → str++ → '\0' 
 * Next iteration: *str is '\0' → exit loop ✓
 * 
 * Example with "a" (length 1):
 * str → 'a' → write 'a' → str++ → '\0' → if (*str) fails
 * → doesn't increment again → safe! ✓
 */
