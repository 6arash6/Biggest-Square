# Hidden Pattern (hidenp)

## Problem
Write a program that takes two strings and checks if the first is a subsequence of the second (all chars in order, not necessarily contiguous).

## Example
Input: "abc" "a1b2c3"
Output: "1"

Input: "abc" "acb"
Output: "0"

## Key Concepts
- Subsequence search
- String iteration

## Sample Solution
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0, j = 0;
    if (ac == 3)
    {
        while (av[1][i] && av[2][j])
        {
            if (av[1][i] == av[2][j])
                i++;
            j++;
        }
        if (!av[1][i])
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- Empty pattern (output: 1)
- Pattern longer than text (output: 0)

---

*Try with different patterns and texts!*
