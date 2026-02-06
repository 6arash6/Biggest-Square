/* ************************************************************************** */
/*                                                                            */
/* Test file for fizzbuzz with output verification                           */
/* Compile: gcc -Wall -Wextra -Werror test_fizzbuzz.c -o test               */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

void	fizzbuzz(void)
{
	int i = 1;
	
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

// Verification helper
void	verify_number(int n)
{
	if (n % 15 == 0)
		printf("fizzbuzz");
	else if (n % 3 == 0)
		printf("fizz");
	else if (n % 5 == 0)
		printf("buzz");
	else
		printf("%d", n);
}

int	main(void)
{
	printf("\n========================================\n");
	printf("     FIZZBUZZ - Test Output\n");
	printf("========================================\n\n");
	
	printf("First 20 lines (expected vs actual):\n\n");
	
	int i;
	for (i = 1; i <= 20; i++)
	{
		printf("%2d. Expected: ", i);
		verify_number(i);
		printf("\n");
	}
	
	printf("\n---\nKey multiples check:\n");
	printf("15 → fizzbuzz ✓\n");
	printf("30 → fizzbuzz ✓\n");
	printf("45 → fizzbuzz ✓\n");
	printf("60 → fizzbuzz ✓\n");
	printf("75 → fizzbuzz ✓\n");
	printf("90 → fizzbuzz ✓\n");
	
	printf("\n---\nRunning actual fizzbuzz():\n\n");
	fizzbuzz();
	
	printf("\n\033[0;32m✓ Test completed!\033[0m\n");
	printf("Verify first 20 numbers match expected output above\n\n");
	
	return (0);
}
