# Print Hexadecimal (print_hex)

## Problem
Write a program that takes a positive integer as argument and prints it in hexadecimal (lowercase), followed by a newline.

## Example
Input: "42"
Output: "2a"

## Key Concepts
- Recursion
- Base conversion
- ASCII arithmetic

## Sample Solution
```c
#include <unistd.h>

void print_hex(unsigned int n)
{
    char *hex = "0123456789abcdef";
    if (n >= 16)
        print_hex(n / 16);
    char c = hex[n % 16];
    write(1, &c, 1);
}

int ft_atoi(char *s)
{
    int n = 0;
    while (*s >= '0' && *s <= '9')
        n = n * 10 + (*s++ - '0');
    return n;
}

int main(int ac, char **av)
{
    if (ac == 2)
        print_hex(ft_atoi(av[1]));
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- Zero
- No arguments
- Non-numeric input (undefined)

---

*Try with different numbers and see the output!*
