# ex07: ft_find_next_prime

## Objective
Write a function that returns the next prime number greater than or equal to nb.

## Function Prototype
```c
int ft_find_next_prime(int nb);
```

## Beginner Explanation
- Find the next prime number >= nb.
- Use ft_is_prime to check each number.

## Example
```c
ft_find_next_prime(10); // returns 11
ft_find_next_prime(17); // returns 17
ft_find_next_prime(20); // returns 23
```

## Steps
1. Loop until ft_is_prime(nb) returns 1.
2. Return nb.

## Manual Testing
Use the provided main.c to test different cases.
