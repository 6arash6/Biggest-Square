# Brainfuck Interpreter (brainfuck)

## Problem
Write a simple interpreter for the Brainfuck language, supporting + - < > [ ] . ,

## Example
Input: "+[-->-[>>+>-----<<]<--<---]>-.>>>+.>++.+++++++..+++.>-.------------.<++++++++.--------.+++.------.--------.>+.", no input
Output: "Hello World!"

## Key Concepts
- Array manipulation
- Loop stack
- Pointer arithmetic

## Sample Solution
```c
#include <unistd.h>

int main(int ac, char **av)
{
    char array[4096] = {0};
    char *ptr = array;
    int i = 0, loop;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] == '>') ptr++;
            else if (av[1][i] == '<') ptr--;
            else if (av[1][i] == '+') ++*ptr;
            else if (av[1][i] == '-') --*ptr;
            else if (av[1][i] == '.') write(1, ptr, 1);
            else if (av[1][i] == '[' && !*ptr)
            {
                loop = 1;
                while (loop && av[1][++i])
                {
                    if (av[1][i] == '[') loop++;
                    if (av[1][i] == ']') loop--;
                }
            }
            else if (av[1][i] == ']' && *ptr)
            {
                loop = 1;
                while (loop && i)
                {
                    if (av[1][i] == ']') loop++;
                    if (av[1][i] == '[') loop--;
                    i--;
                }
            }
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- Unmatched brackets (undefined)
- Pointer out of bounds (undefined)

---

*Try with different Brainfuck programs!*
