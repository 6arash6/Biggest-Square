# ex06: ft_is_prime

## Objective
Write a function that returns 1 if the number is prime, otherwise 0.

## Function Prototype
```c
int ft_is_prime(int nb);
```

## Beginner Explanation
- A prime number is only divisible by 1 and itself.
- If nb <= 1, return 0.
- Loop from 2 to sqrt(nb), check divisibility.

## Example
```c
ft_is_prime(2); // returns 1
ft_is_prime(4); // returns 0
ft_is_prime(17); // returns 1
ft_is_prime(1); // returns 0
```

## Steps
1. If nb <= 1, return 0.
2. Loop i from 2 to sqrt(nb).
3. If nb % i == 0, return 0.
4. If loop finishes, return 1.

## Manual Testing
Use the provided main.c to test different cases.
