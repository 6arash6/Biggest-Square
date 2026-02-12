# Rotate Words in String (rostring)

## Problem
Write a program that takes a string and rotates the first word to the end, preserving word order.

## Example
Input: "abc def ghi"
Output: "def ghi abc"

## Key Concepts
- String parsing
- Word boundaries

## Sample Solution
```c
#include <unistd.h>

void putstr(char *s) { while (*s) write(1, s++, 1); }

int main(int ac, char **av)
{
    int i = 0, j = 0, first = 0, start = 0, end = 0;
    if (ac == 2)
    {
        // Skip leading spaces
        while (av[1][i] == ' ' || av[1][i] == '\t') i++;
        start = i;
        // Find end of first word
        while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t') i++;
        end = i;
        // Print rest of words
        while (av[1][i])
        {
            while (av[1][i] == ' ' || av[1][i] == '\t') i++;
            if (av[1][i])
            {
                if (first++) write(1, " ", 1);
                j = i;
                while (av[1][j] && av[1][j] != ' ' && av[1][j] != '\t') write(1, &av[1][j++], 1);
                i = j;
            }
        }
        // Print first word at end
        if (first) write(1, " ", 1);
        for (j = start; j < end; j++) write(1, &av[1][j], 1);
    }
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- Only one word
- Leading/trailing spaces

---

*Try with different sentences for practice!*
