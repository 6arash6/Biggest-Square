# ex02: ft_iterative_power

## Objective
Write a function that returns nb raised to the power using iteration.

## Function Prototype
```c
int ft_iterative_power(int nb, int power);
```

## Beginner Explanation
- nb^power means multiplying nb by itself power times.
- If power < 0, return 0.
- Use a loop to multiply nb.

## Example
```c
ft_iterative_power(2, 3); // returns 8
ft_iterative_power(5, 0); // returns 1
ft_iterative_power(2, -1); // returns 0
```

## Steps
1. If power < 0, return 0.
2. Initialize result to 1.
3. Loop power times, multiply result by nb.
4. Return result.

## Manual Testing
Use the provided main.c to test different cases.
