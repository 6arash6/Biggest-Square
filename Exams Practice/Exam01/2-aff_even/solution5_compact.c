/* ************************************************************************** */
/*                                                                            */
/* SOLUTION 5: Super Compact Version (exam speed coding)                     */
/* Minimal lines - good for time pressure in exams                           */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i = -1;
	
	if (ac == 2)
		while (av[1][++i])
			if (!(i & 1))
				write(1, av[1] + i, 1);
	write(1, "\n", 1);
	return (0);
}

/* 
 * Breakdown of the compact tricks:
 * 
 * 1. int i = -1;
 *    - Start at -1 so ++i in while makes it 0 first
 * 
 * 2. while (av[1][++i])
 *    - Pre-increment: increment BEFORE using
 *    - First iteration: i becomes 0, checks av[1][0]
 * 
 * 3. if (!(i & 1))
 *    - Negation of odd check
 *    - i & 1 == 0 is the same as !(i & 1)
 *    - Even more compact!
 * 
 * 4. write(1, av[1] + i, 1);
 *    - Pointer arithmetic instead of &av[1][i]
 *    - av[1] + i moves pointer i positions ahead
 * 
 * Trade-offs:
 * ✓ Very compact - fast to type in exams
 * ✓ Shows advanced understanding
 * ✗ Less readable for others
 * ✗ Harder to debug if something goes wrong
 * 
 * When to use:
 * - In exams when time is critical
 * - When you're 100% confident in syntax
 * - NOT in collaborative projects (readability!)
 */
