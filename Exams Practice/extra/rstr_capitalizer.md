# Capitalize Last Letter of Each Word (rstr_capitalizer)

## Problem
Write a program that takes a string and capitalizes the last letter of each word, making all other letters lowercase.

## Example
Input: "hello WORLD"
Output: "hellO worlD"

## Key Concepts
- String iteration
- Word boundary detection
- ASCII arithmetic

## Sample Solution
```c
#include <unistd.h>

int is_alpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

int main(int ac, char **av)
{
    int i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            char c = av[1][i];
            if (is_alpha(c) && (!av[1][i+1] || !is_alpha(av[1][i+1])))
            {
                if (c >= 'a' && c <= 'z') c -= 32;
            }
            else if (c >= 'A' && c <= 'Z')
                c += 32;
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- Empty string
- No arguments
- Non-letter characters

---

*Try with different sentences for practice!*
