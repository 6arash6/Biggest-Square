# Parameter Sum (paramsum)

## Problem
Write a program that prints the number of arguments passed to it (excluding the program name).

## Example
Input: ./paramsum 1 2 3
Output: 3

## Key Concepts
- argc usage

## Sample Solution
```c
#include <unistd.h>

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
    (void)av;
    putnbr(ac - 1);
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- No arguments (output: 0)

---

*Try with different numbers of arguments!*
