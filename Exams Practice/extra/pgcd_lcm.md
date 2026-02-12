# GCD & LCM (pgcd, lcm)

## Problem
Write programs to compute:
- **GCD (pgcd):** Greatest common divisor of two numbers
- **LCM (lcm):** Least common multiple of two numbers

## Example
Input: "42 24"
Output (pgcd): "6"
Output (lcm): "168"

## Key Concepts
- Euclidean algorithm
- Multiplication/division

## Sample Solution (GCD)
```c
#include <unistd.h>

int ft_atoi(char *s) { int n = 0; while (*s >= '0' && *s <= '9') n = n * 10 + (*s++ - '0'); return n; }

void putnbr(int n) { char c; if (n >= 10) putnbr(n / 10); c = n % 10 + '0'; write(1, &c, 1); }

int main(int ac, char **av)
{
    int a, b, t;
    if (ac == 3)
    {
        a = ft_atoi(av[1]); b = ft_atoi(av[2]);
        while (b) { t = a % b; a = b; b = t; }
        putnbr(a);
    }
    write(1, "\n", 1);
    return 0;
}
```

## Sample Solution (LCM)
```c
#include <unistd.h>

int ft_atoi(char *s) { int n = 0; while (*s >= '0' && *s <= '9') n = n * 10 + (*s++ - '0'); return n; }

void putnbr(int n) { char c; if (n >= 10) putnbr(n / 10); c = n % 10 + '0'; write(1, &c, 1); }

int gcd(int a, int b) { int t; while (b) { t = a % b; a = b; b = t; } return a; }

int main(int ac, char **av)
{
    int a, b, lcm;
    if (ac == 3)
    {
        a = ft_atoi(av[1]); b = ft_atoi(av[2]);
        lcm = (a * b) / gcd(a, b);
        putnbr(lcm);
    }
    write(1, "\n", 1);
    return 0;
}
```

## Edge Cases
- Zero or negative input (undefined)
- No arguments

---

*Try with different pairs for practice!*
