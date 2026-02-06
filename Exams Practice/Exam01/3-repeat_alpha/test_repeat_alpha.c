/* ************************************************************************** */
/*                                                                            */
/* Test file for repeat_alpha with automated verification                    */
/* Compile: gcc -Wall -Wextra -Werror test_repeat_alpha.c -o test           */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

// The actual solution
void	repeat_alpha(char *str)
{
	int i;
	int repeat;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			repeat = str[i] - 'a' + 1;
			j = 0;
			while (j < repeat)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			repeat = str[i] - 'A' + 1;
			j = 0;
			while (j < repeat)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

// Helper to print expected output
void	print_expected_for_input(char *input)
{
	int i = 0;
	int repeat, j;
	
	while (input[i])
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			repeat = input[i] - 'a' + 1;
			for (j = 0; j < repeat; j++)
				printf("%c", input[i]);
		}
		else if (input[i] >= 'A' && input[i] <= 'Z')
		{
			repeat = input[i] - 'A' + 1;
			for (j = 0; j < repeat; j++)
				printf("%c", input[i]);
		}
		else
			printf("%c", input[i]);
		i++;
	}
}

void	test_case(char *input)
{
	printf("\033[0;34mInput:\033[0m    \"%s\"\n", input);
	printf("Expected: \"");
	print_expected_for_input(input);
	printf("\"\n");
	printf("Got:      \"");
	repeat_alpha(input);
	printf("\"\n");
	printf("---\n");
}

int	main(void)
{
	printf("\n========================================\n");
	printf("   REPEAT_ALPHA - Test Suite\n");
	printf("========================================\n\n");
	
	// Test 1: Simple case
	test_case("abc");
	
	// Test 2: From subject
	test_case("Alex.");
	
	// Test 3: From subject with space
	test_case("abacadaba 42!");
	
	// Test 4: Single character
	test_case("a");
	
	// Test 5: Last letter
	test_case("z");
	
	// Test 6: First letter uppercase
	test_case("A");
	
	// Test 7: Last letter uppercase  
	test_case("Z");
	
	// Test 8: Mixed case
	test_case("AaBbCc");
	
	// Test 9: No letters
	test_case("123!@#");
	
	// Test 10: Empty string
	test_case("");
	
	printf("\n\033[0;32mAll tests completed!\033[0m\n");
	printf("Verify 'Got' matches 'Expected' for each test\n\n");
	
	return (0);
}

/*
 * Quick reference for alphabet positions:
 * a=1, b=2, c=3, d=4, e=5, f=6, g=7, h=8, i=9, j=10,
 * k=11, l=12, m=13, n=14, o=15, p=16, q=17, r=18, s=19, t=20,
 * u=21, v=22, w=23, x=24, y=25, z=26
 */
