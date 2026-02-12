# Multiplication Table (tab_mult)

## Problem
Write a program that prints the multiplication table for a given number (1-9).

## Example
Input: "4"
Output:
1 x 4 = 4
2 x 4 = 8
...
9 x 4 = 36

## Key Concepts
- Loops
- ASCII arithmetic

## Sample Solution
```c
#include <unistd.h>

void putnbr(int n) { char c; if (n >= 10) putnbr(n / 10); c = n % 10 + '0'; write(1, &c, 1); }

int ft_atoi(char *s) { int n = 0; while (*s >= '0' && *s <= '9') n = n * 10 + (*s++ - '0'); return n; }

int main(int ac, char **av)
{
    int n;
    if (ac == 2)
    {
        n = ft_atoi(av[1]);
        for (int i = 1; i <= 9; i++)
        {
            putnbr(i); write(1, " x ", 3); putnbr(n); write(1, " = ", 3); putnbr(i * n); write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- No arguments (prints newline)
- Input not 1-9 (prints nothing or newline)

---

*Try with different numbers for practice!*
