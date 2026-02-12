# 🔄 Case Swap Tutorial

## Problem
Write a program that takes a string and swaps the case of each letter:
- Lowercase → Uppercase
- Uppercase → Lowercase

## Example
Input: "Hello42World!"
Output: "hELLO42wORLD!"

## Key Concepts
- ASCII arithmetic
- Character checks

## Sample Solution
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            char c = av[1][i];
            if (c >= 'a' && c <= 'z')
                c -= 32; // to uppercase
            else if (c >= 'A' && c <= 'Z')
                c += 32; // to lowercase
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

## Edge Cases
- Empty string
- No arguments
- Non-letter characters (unchanged)

---

*Add test file and practice variants as needed.*
