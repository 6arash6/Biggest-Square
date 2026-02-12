# Reverse Polish Notation Calculator (rpn_calc)

## Problem
Write a program that evaluates an expression in Reverse Polish Notation (RPN).

## Example
Input: "3 4 + 2 * 7 /"
Output: "2"

## Key Concepts
- Stack simulation
- Token parsing

## Sample Solution
```c
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int stack[4096], sp = 0, a, b, n;
    if (ac == 2)
    {
        char *s = av[1];
        while (*s)
        {
            while (*s == ' ') s++;
            if (*s >= '0' && *s <= '9')
            {
                n = 0;
                while (*s >= '0' && *s <= '9') n = n * 10 + (*s++ - '0');
                stack[sp++] = n;
            }
            else if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%')
            {
                if (sp < 2) break;
                b = stack[--sp]; a = stack[--sp];
                if (*s == '+') stack[sp++] = a + b;
                if (*s == '-') stack[sp++] = a - b;
                if (*s == '*') stack[sp++] = a * b;
                if (*s == '/' && b) stack[sp++] = a / b;
                if (*s == '%' && b) stack[sp++] = a % b;
                s++;
            }
            else if (*s)
                s++;
        }
        if (sp == 1)
        {
            char buf[12];
            int len = 0, val = stack[0];
            if (val == 0) buf[len++] = '0';
            else
            {
                int tmp = val, neg = 0;
                if (tmp < 0) { neg = 1; tmp = -tmp; }
                while (tmp) { buf[len++] = tmp % 10 + '0'; tmp /= 10; }
                if (neg) buf[len++] = '-';
                for (int i = len - 1; i >= 0; i--) write(1, &buf[i], 1);
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- Invalid expression (prints newline)
- Division by zero (undefined)

---

*Try with different RPN expressions!*
