# ex05: ft_sqrt

## Objective
Write a function that returns the square root of a number if it is a perfect square, otherwise 0.

## Function Prototype
```c
int ft_sqrt(int nb);
```

## Beginner Explanation
- Square root of nb is a number i such that i*i = nb.
- If nb < 0, return 0.
- Loop to find i where i*i == nb.
- If not found, return 0.

## Example
```c
ft_sqrt(9); // returns 3
ft_sqrt(16); // returns 4
ft_sqrt(10); // returns 0
ft_sqrt(-1); // returns 0
```

## Steps
1. If nb < 0, return 0.
2. Loop i from 0 upwards.
3. If i*i == nb, return i.
4. If i*i > nb, return 0.

## Manual Testing
Use the provided main.c to test different cases.
