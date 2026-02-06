#include <unistd.h>

// Alternative solution: void return type (no return value)
void	ft_rev_print_alt(char *str)
{
	int i = 0;
	int last;

	// Count the string length
	while (str[i])
		i++;

	// 'last' receives the String Length - 1
	last = i - 1;
	while (last >= 0)
	{
		// Prints the char in this index
		write(1, &str[last], 1);

		// Go to the next indices
		last--;
	}
	// Print the new line only at the end of the string
	write(1, "\n", 1);
	// No return statement needed
}

int	main(int argc, char **argv)
{
	// only calls the function if you have only 2 arguments
	if (argc == 2)

		// Send to print the argument in position 1 using the alternative function
		ft_rev_print_alt(argv[1]);
	return (0);
}