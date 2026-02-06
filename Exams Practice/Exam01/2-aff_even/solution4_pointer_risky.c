/* ************************************************************************** */
/*                                                                            */
/* SOLUTION 4: Pointer += 2 (ELEGANT BUT RISKY)                              */
/* Direct jump to next even position                                         */
/* ⚠️  WARNING: Can cause undefined behavior with odd-length strings         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char *str;

	if (ac == 2)
	{
		str = av[1];
		
		while (*str)
		{
			write(1, str, 1);	// Print current char
			str += 2;		// Jump directly 2 positions ahead
		}
	}
	
	write(1, "\n", 1);
	return (0);
}

/* 
 * ⚠️  DANGER ZONE - Why this can be problematic:
 * 
 * Example with "hello" (length 5 - ODD):
 * 
 * str → 'h' (pos 0) → write 'h' → str += 2
 * str → 'l' (pos 2) → write 'l' → str += 2
 * str → 'o' (pos 4) → write 'o' → str += 2
 * str → ??? (pos 6) → PAST END OF STRING!
 * 
 * What happens:
 * - str is now pointing 1 byte past '\0'
 * - Reading *str is UNDEFINED BEHAVIOR
 * - Might work, might crash, might print garbage
 * - NOT SAFE for production code!
 * 
 * Example with "hi" (length 2 - EVEN):
 * 
 * str → 'h' (pos 0) → write 'h' → str += 2
 * str → '\0' (pos 2) → *str is '\0' → loop exits
 * This case works fine! ✓
 * 
 * ==================================================================
 * CONCLUSION: 
 * - This version is clean-looking and elegant
 * - BUT it's dangerous with odd-length strings
 * - In 42 exams, moulinette might test with odd lengths
 * - Use solution3_pointer_safe.c instead!
 * ==================================================================
 * 
 * If you REALLY want to use += 2, you need extra checks:
 * 
 *   while (*str && *(str + 1))  // Check both current and next
 *   {
 *       write(1, str, 1);
 *       str += 2;
 *   }
 *   if (*str)  // Handle last char if string length is odd
 *       write(1, str, 1);
 * 
 * But that defeats the simplicity! Just use solution 3.
 */
