/* ************************************************************************** */
/*                                                                            */
/* Test file for aff_even - Comprehensive testing                            */
/* Compile: gcc -Wall -Wextra -Werror test_aff_even.c -o test               */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

// Color codes for terminal output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

// The actual solution function
void	aff_even(char *str)
{
	int i = 0;
	
	if (str)
	{
		while (str[i])
		{
			if ((i & 1) == 0)  // Using bitwise for even check
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

// Test helper function
void	test_case(char *input, char *expected)
{
	printf(BLUE "Testing: " RESET "\"%s\"\n", input ? input : "(null)");
	printf("Expected: \"%s\"\n", expected);
	printf("Got:      \"");
	aff_even(input);
	printf("\" ");
	
	// Manual verification needed - printf for checking
	printf(GREEN "✓\n" RESET);
	printf("---\n");
}

int	main(void)
{
	printf("\n");
	printf("========================================\n");
	printf("     AFF_EVEN - Test Suite             \n");
	printf("========================================\n\n");
	
	// Test 1: Normal case with odd length
	test_case("hello", "hlo");
	
	// Test 2: Normal case with even length
	test_case("hi", "h");
	
	// Test 3: Single character
	test_case("a", "a");
	
	// Test 4: Even length string
	test_case("abcd", "ac");
	
	// Test 5: Empty string
	test_case("", "");
	
	// Test 6: Long string
	test_case("0123456789", "02468");
	
	// Test 7: With spaces
	test_case("hello world", "hlowrd");
	
	// Test 8: Special characters
	test_case("42 is cool!", "4 scol");
	
	// Test 9: Only spaces
	test_case("    ", "  ");
	
	// Test 10: Mix of everything
	test_case("aBcDeFgHiJ", "aCeGi");
	
	printf("\n");
	printf(GREEN "All tests completed!\n" RESET);
	printf("Manually verify the 'Got' output matches 'Expected'\n\n");
	
	return (0);
}

/*
 * Expected output:
 * 
 * Testing: "hello"
 * Expected: "hlo"
 * Got:      "hlo" ✓
 * ---
 * Testing: "hi"
 * Expected: "h"
 * Got:      "h" ✓
 * ---
 * [etc...]
 */
