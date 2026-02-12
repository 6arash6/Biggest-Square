# Command-Line Options as Bit Flags (options)

## Problem
Write a program that parses command-line options (e.g., -a -b -c) and prints a bit field representing which options are set.

## Example
Input: "-abc"
Output: "0000000000000000000000111"

## Key Concepts
- Bitwise operations
- Command-line parsing

## Sample Solution
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int flags = 0;
    for (int i = 1; i < ac; i++)
    {
        if (av[i][0] == '-')
        {
            for (int j = 1; av[i][j]; j++)
                if (av[i][j] >= 'a' && av[i][j] <= 'z')
                    flags |= (1 << (av[i][j] - 'a'));
        }
    }
    for (int i = 25; i >= 0; i--)
        write(1, (flags & (1 << i)) ? "1" : "0", 1);
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- No options (all zeros)
- Invalid option (ignored)

---

*Try with different combinations of options!*
