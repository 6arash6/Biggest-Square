#include <unistd.h>

// Helper function to print a single character
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Prints an integer to standard output (iterative, no modulo)
void ft_putnbr_nomod(int nb)
{
    unsigned int n;
    if (nb < 0)
    {
        write(1, "-", 1);
        n = (unsigned int)(-nb);
    }
    else
    {
        n = (unsigned int)nb;
    }

    if (n == 0)
    {
        write(1, "0", 1);
        return;
    }

    unsigned int pow = 1;
    unsigned int temp = n;
    // Find the highest power of 10 less than or equal to n
    while (temp >= 10)
    {
        pow *= 10;
        temp /= 10;
    }

    while (pow > 0)
    {
        unsigned int digit = 0;
        unsigned int div = pow;
        // Subtract div from n until n < div, counting how many times
        while (n >= div)
        {
            n -= div;
            digit++;
        }
        char c = digit + '0';
        write(1, &c, 1);
        pow /= 10;
    }
}
