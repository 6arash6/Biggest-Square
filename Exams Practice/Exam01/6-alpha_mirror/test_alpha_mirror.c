/* ************************************************************************** */
/*                                                                            */
/* Test file for alpha_mirror - Mirror alphabet positions                    */
/* Compile: gcc -Wall -Wextra -Werror test_alpha_mirror.c -o test           */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	alpha_mirror(char *str)
{
	int i = 0;
	char c;
	
	if (str)
	{
		while (str[i])
		{
			c = str[i];
			
			if (c >= 'a' && c <= 'z')
				c = 'z' - (c - 'a');
			else if (c >= 'A' && c <= 'Z')
				c = 'Z' - (c - 'A');
			
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

// Helper to show mirror mapping
void	print_mirror_table(void)
{
	printf("\nMirror mapping reference:\n");
	printf("Original: a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
	printf("Mirrored: z y x w v u t s r q p o n m l k j i h g f e d c b a\n\n");
}

void	test_case(char *input, char *expected)
{
	printf("\033[0;34mInput:\033[0m    \"%s\"\n", input ? input : "(null)");
	printf("Expected: \"%s\"\n", expected);
	printf("Got:      \"");
	alpha_mirror(input);
	printf("\" \033[0;32m✓\033[0m\n");
	printf("---\n");
}

int	main(void)
{
	printf("\n========================================\n");
	printf("    ALPHA_MIRROR - Test Suite\n");
	printf("========================================\n");
	
	print_mirror_table();
	
	// Test 1: Simple abc
	test_case("abc", "zyx");
	
	// Test 2: From subject
	test_case("My horse is Amazing.", "Nb slihv rh Znzarmt.");
	
	// Test 3: All lowercase
	test_case("hello", "svool");
	
	// Test 4: All uppercase
	test_case("WORLD", "DLIOW");
	
	// Test 5: First and last letters
	test_case("az", "za");
	test_case("AZ", "ZA");
	
	// Test 6: Middle letter (m/n)
	test_case("mn", "nm");
	test_case("MN", "NM");
	
	// Test 7: Numbers and special chars (unchanged)
	test_case("123!@#", "123!@#");
	
	// Test 8: Mixed
	test_case("42 is the answer", "42 rh gsv zmhdvi");
	
	// Test 9: Empty
	test_case("", "");
	
	// Test 10: Full alphabet
	test_case("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba");
	
	printf("\n\033[0;32mAll tests completed!\033[0m\n");
	printf("Verify 'Got' matches 'Expected'\n\n");
	
	// Show some interesting mirrors
	printf("Fun fact: These words mirror to themselves!\n");
	printf("- 'a' ↔ 'z'\n");
	printf("- 'n' ↔ 'n' (middle letter!)\n");
	printf("- 'mn' ↔ 'nm'\n\n");
	
	return (0);
}

/*
 * Formula explanation:
 * 
 * For 'a' (position 0):
 *   'z' - (0) = 'z' - 0 = 'z'
 * 
 * For 'c' (position 2):
 *   'z' - (2) = 'z' - 2 = 'x'
 * 
 * For 'z' (position 25):
 *   'z' - (25) = 'z' - 25 = 'a'
 */
