# Base-N String to Int (ft_atoi_base)

## Problem
Write a function that converts a string in a given base (2-16) to an integer.

## Example
Input: "1010" base 2
Output: 10

Input: "2a" base 16
Output: 42

## Key Concepts
- Base conversion
- Character checks

## Sample Solution
```c
#include <unistd.h>

int ft_atoi_base(const char *str, int base)
{
    int n = 0, sign = 1;
    if (*str == '-') { sign = -1; str++; }
    while (*str)
    {
        int d;
        if (*str >= '0' && *str <= '9')
            d = *str - '0';
        else if (*str >= 'a' && *str <= 'f')
            d = *str - 'a' + 10;
        else if (*str >= 'A' && *str <= 'F')
            d = *str - 'A' + 10;
        else
            break;
        if (d >= base)
            break;
        n = n * base + d;
        str++;
    }
    return n * sign;
}

// Example usage in main omitted for brevity
```

## Edge Cases
- Invalid characters
- Negative numbers
- Base out of range

---

*Try with different bases and strings!*
