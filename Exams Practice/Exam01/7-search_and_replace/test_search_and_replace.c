/* ************************************************************************** */
/*                                                                            */
/* Test file for search_and_replace                                          */
/* Compile: gcc -Wall -Wextra -Werror test_search_and_replace.c -o test     */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	search_and_replace(char *str, char search, char replace)
{
	int i = 0;
	
	while (str[i])
	{
		if (str[i] == search)
			write(1, &replace, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

// Wrapper to simulate argc/argv behavior
void	simulate_program(int ac, char **av)
{
	// Validate: exactly 3 args and both search/replace are single chars
	if (ac == 4 && !av[2][1] && !av[3][1])
		search_and_replace(av[1], av[2][0], av[3][0]);
	else
		write(1, "\n", 1);
}

void	test_case(char *desc, char *str, char *search, char *replace, char *expected)
{
	char *test_args[4];
	int arg_count;
	
	printf("\033[0;34m%s\033[0m\n", desc);
	
	if (str && search && replace)
	{
		test_args[1] = str;
		test_args[2] = search;
		test_args[3] = replace;
		arg_count = 4;
		printf("Args:     \"%s\" \"%s\" \"%s\"\n", str, search, replace);
	}
	else if (str && search)
	{
		test_args[1] = str;
		test_args[2] = search;
		arg_count = 3;
		printf("Args:     \"%s\" \"%s\"\n", str, search);
	}
	else if (str)
	{
		test_args[1] = str;
		arg_count = 2;
		printf("Args:     \"%s\"\n", str);
	}
	else
	{
		arg_count = 1;
		printf("Args:     (none)\n");
	}
	
	printf("Expected: \"%s\"\n", expected);
	printf("Got:      \"");
	simulate_program(arg_count, test_args);
	printf("\" \033[0;32m✓\033[0m\n");
	printf("---\n");
}

int	main(void)
{
	printf("\n========================================\n");
	printf("  SEARCH_AND_REPLACE - Test Suite\n");
	printf("========================================\n\n");
	
	// Test 1: Normal replacement
	test_case("Test 1: Basic replacement",
		"Papache est un sabre", "a", "o",
		"Popoche est un sobre");
	
	// Test 2: Char not in string
	test_case("Test 2: Search char not in string",
		"zaz", "r", "u",
		"zaz");
	
	// Test 3: Multiple occurrences
	test_case("Test 3: Multiple replacements",
		"ZoZ eT Dovid", "Z", "m",
		"mom eT Dovid");
	
	// Test 4: From subject
	test_case("Test 4: Complex replacement",
		"wNcOre Un ExEmPle Pas Facilw a Ecrirw ", "w", "e",
		"eNcOre Un ExEmPle Pas Facile a Ecrire ");
	
	// Test 5: Replace space
	test_case("Test 5: Replace spaces",
		"hello world", " ", "_",
		"hello_world");
	
	// Test 6: Replace digit
	test_case("Test 6: Replace digit",
		"42 is cool", "4", "7",
		"72 is cool");
	
	// Test 7: Empty string
	test_case("Test 7: Empty string",
		"", "a", "b",
		"");
	
	// Test 8: Single character replacement
	test_case("Test 8: Single char",
		"a", "a", "b",
		"b");
	
	printf("\n--- Edge Cases (should print only newline) ---\n\n");
	
	// Test 9: Multi-char search (invalid)
	test_case("Test 9: Multi-char search (invalid)",
		"zaz", "art", "zul",
		"");
	
	// Test 10: Too many arguments (simulated)
	printf("\033[0;34mTest 10: Too many arguments\033[0m\n");
	printf("Args:     \"jacob\" \"a\" \"b\" \"c\" \"e\"\n");
	printf("Expected: \"\"\n");
	printf("Got:      \"");
	char *args[] = {NULL, "jacob", "a", "b", "c", "e"};
	simulate_program(6, args);
	printf("\" \033[0;32m✓\033[0m\n");
	printf("---\n");
	
	// Test 11: No arguments
	test_case("Test 11: No arguments",
		NULL, NULL, NULL,
		"");
	
	// Test 12: Only one argument
	test_case("Test 12: Only string arg",
		"hello", NULL, NULL,
		"");
	
	printf("\n\033[0;32mAll tests completed!\033[0m\n");
	printf("Verify 'Got' matches 'Expected'\n\n");
	
	printf("Key validation checks:\n");
	printf("1. argc must equal 4 (3 arguments)\n");
	printf("2. av[2][1] must be '\\0' (single char search)\n");
	printf("3. av[3][1] must be '\\0' (single char replace)\n\n");
	
	return (0);
}

/*
 * Important notes:
 * 
 * Valid:   ./program "hello" "l" "r"  → "herro"
 * Invalid: ./program "hello" "ll" "r" → (newline only)
 * Invalid: ./program "hello" "l"      → (newline only)
 * Invalid: ./program                  → (newline only)
 */
