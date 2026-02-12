# Bracket Validation (brackets)

## Problem
Write a program that checks if all types of brackets in a string are correctly matched and nested.

## Example
Input: "{[()]}"
Output: "OK"

Input: "([)]"
Output: "Error"

## Key Concepts
- Stack simulation
- Matching pairs

## Sample Solution
```c
#include <unistd.h>

int match(char a, char b) { return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'); }

int check(char *s)
{
    char stack[4096];
    int top = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[top++] = s[i];
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (top == 0 || !match(stack[top - 1], s[i]))
                return 0;
            top--;
        }
    }
    return (top == 0);
}

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        write(1, check(av[i]) ? "OK\n" : "Error\n", check(av[i]) ? 3 : 6);
    return 0;
}
```

## Edge Cases
- Empty string (OK)
- Only opening or closing brackets (Error)

---

*Try with different bracket strings!*
