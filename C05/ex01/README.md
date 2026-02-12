# ex01: ft_recursive_factorial

## Objective
Write a function that returns the factorial of a number using recursion.

## Function Prototype
```c
int ft_recursive_factorial(int nb);
```

## Beginner Explanation
- Factorial of n is n * (n-1) * ... * 1.
- If nb < 0, return 0.
- Use recursion: function calls itself with nb-1.

## Example
```c
ft_recursive_factorial(5); // returns 120
ft_recursive_factorial(0); // returns 1
ft_recursive_factorial(-1); // returns 0
```

## Steps
1. If nb < 0, return 0.
2. If nb == 0, return 1.
3. Return nb * ft_recursive_factorial(nb - 1).

## Manual Testing
Use the provided main.c to test different cases.
