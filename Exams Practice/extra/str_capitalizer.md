# Capitalize First Letter of Each Word (str_capitalizer)

## Problem
Write a program that takes a string and capitalizes the first letter of each word, making all other letters lowercase.

## Example
Input: "hello WORLD"
Output: "Hello World"

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
    int i = 0, new_word = 1;
    if (ac == 2)
    {
        while (av[1][i])
        {
            char c = av[1][i];
            if (is_alpha(c))
            {
                if (new_word && c >= 'a' && c <= 'z')
                    c -= 32;
                else if (!new_word && c >= 'A' && c <= 'Z')
                    c += 32;
                new_word = 0;
            }
            else
                new_word = 1;
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
