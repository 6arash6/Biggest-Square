# ex03: ft_recursive_power

## Objective
Write a function that returns nb raised to the power using recursion.

## Function Prototype
```c
int ft_recursive_power(int nb, int power);
```

## Beginner Explanation
- nb^power means multiplying nb by itself power times.
- If power < 0, return 0.
- Use recursion: function calls itself with power-1.

## Example
```c
ft_recursive_power(2, 3); // returns 8
ft_recursive_power(5, 0); // returns 1
ft_recursive_power(2, -1); // returns 0
```

## Steps
1. If power < 0, return 0.
2. If power == 0, return 1.
3. Return nb * ft_recursive_power(nb, power - 1).

## Manual Testing
Use the provided main.c to test different cases.
