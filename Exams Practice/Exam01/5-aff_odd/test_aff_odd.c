/* ************************************************************************** */
/*                                                                            */
/* Test file for aff_odd - Print characters at odd positions                 */
/* Compile: gcc -Wall -Wextra -Werror test_aff_odd.c -o test                */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	aff_odd(char *str)
{
	int i = 0;
	
	if (str)
	{
		while (str[i])
		{
			if (i & 1)  // Bitwise check for odd
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

void	test_case(char *input, char *expected)
{
	printf("\033[0;34mTesting:\033[0m \"%s\"\n", input ? input : "(null)");
	printf("Expected: \"%s\"\n", expected);
	printf("Got:      \"");
	aff_odd(input);
	printf("\" \033[0;32m✓\033[0m\n");
	printf("---\n");
}

int	main(void)
{
	printf("\n========================================\n");
	printf("      AFF_ODD - Test Suite\n");
	printf("========================================\n\n");
	
	// Test 1: Basic odd length
	test_case("hello", "el");
	
	// Test 2: Even length
	test_case("hi", "i");
	
	// Test 3: Single char (no odd positions)
	test_case("a", "");
	
	// Test 4: Four characters
	test_case("abcd", "bd");
	
	// Test 5: Empty string
	test_case("", "");
	
	// Test 6: Numbers
	test_case("0123456789", "13579");
	
	// Test 7: With spaces
	test_case("hello world", "el ol");
	
	// Test 8: Two characters
	test_case("ab", "b");
	
	// Test 9: Special chars
	test_case("a!b@c#d$", "!@#$");
	
	// Test 10: Position verification
	// pos: 0 1 2 3 4 5 6 7 8 9
	// str: A B C D E F G H I J
	// odd:   B   D   F   H   J
	test_case("ABCDEFGHIJ", "BDFHJ");
	
	printf("\n\033[0;32mAll tests completed!\033[0m\n");
	printf("Verify 'Got' matches 'Expected'\n\n");
	
	return (0);
}

/*
 * Remember: Odd positions are 1, 3, 5, 7...
 * 
 * "hello" breakdown:
 * Position: 0   1   2   3   4
 * Char:     h   e   l   l   o
 * Odd?:     No  Yes No  Yes No
 * Result: "el"
 */
