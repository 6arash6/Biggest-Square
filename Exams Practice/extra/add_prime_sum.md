# Add Prime Sum (add_prime_sum)

## Problem
Write a program that takes a positive integer and prints the sum of all prime numbers less than or equal to it.

## Example
Input: "10"
Output: "17"  // 2+3+5+7=17

## Key Concepts
- Prime checking
- Loops
- Summation

## Sample Solution
```c
#include <unistd.h>

int ft_atoi(char *s)
{
    int n = 0;
    while (*s >= '0' && *s <= '9')
        n = n * 10 + (*s++ - '0');
    return n;
}

int is_prime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void putnbr(int n)
{
    char c;
    if (n >= 10)
        putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    int n, sum = 0;
    if (ac == 2)
    {
        n = ft_atoi(av[1]);
        for (int i = 2; i <= n; i++)
            if (is_prime(i))
                sum += i;
        putnbr(sum);
    }
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- n < 2 (output: 0)
- No arguments

---

*Try with different values for more practice!*
