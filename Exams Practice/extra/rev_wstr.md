# Reverse Words in String (rev_wstr)

## Problem
Write a program that takes a string and prints its words in reverse order.

## Example
Input: "abc def ghi"
Output: "ghi def abc"

## Key Concepts
- String parsing
- Word boundaries
- Reverse printing

## Sample Solution
```c
#include <unistd.h>

void putstr(char *s, int len) { for (int i = 0; i < len; i++) write(1, &s[i], 1); }

int main(int ac, char **av)
{
    int i = 0, j, k, words = 0, pos[100][2];
    if (ac == 2)
    {
        // Find word positions
        while (av[1][i])
        {
            while (av[1][i] == ' ' || av[1][i] == '\t') i++;
            if (av[1][i])
            {
                pos[words][0] = i;
                while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t') i++;
                pos[words][1] = i;
                words++;
            }
        }
        // Print words in reverse
        for (k = words - 1; k >= 0; k--)
        {
            if (k < words - 1) write(1, " ", 1);
            putstr(av[1] + pos[k][0], pos[k][1] - pos[k][0]);
        }
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
