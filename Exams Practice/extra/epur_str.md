# Normalize Spaces (epur_str)

## Problem
Write a program that takes a string and prints it with exactly one space between words, removing leading/trailing/multiple spaces.

## Example
Input: "   Hello   world   42!  "
Output: "Hello world 42!"

## Key Concepts
- String iteration
- Skipping spaces

## Sample Solution
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0, word = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            while (av[1][i] == ' ' || av[1][i] == '\t')
                i++;
            if (av[1][i] && word)
                write(1, " ", 1);
            while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            {
                write(1, &av[1][i], 1);
                i++;
            }
            if (av[1][i])
                word = 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## Edge Cases
- Only spaces
- Empty string
- No arguments

---

*Practice with test cases and try variants like expand_str!*
