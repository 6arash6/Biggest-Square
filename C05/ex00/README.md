# ex00: ft_iterative_factorial

## Objective
Write a function that returns the factorial of a number using iteration.

## Function Prototype
```c
int ft_iterative_factorial(int nb);
```

## Beginner Explanation
- Factorial of n is n * (n-1) * ... * 1.
- If nb < 0, return 0.
- Use a loop to multiply numbers down to 1.

## Example
```c
ft_iterative_factorial(5); // returns 120
ft_iterative_factorial(0); // returns 1
ft_iterative_factorial(-1); // returns 0
```

## Steps
1. If nb < 0, return 0.
2. Initialize result to 1.
3. Loop from nb down to 1, multiply result.
4. Return result.

## Manual Testing
Use the provided main.c to test different cases.
