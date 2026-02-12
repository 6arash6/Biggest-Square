# ex04: ft_fibonacci

## Objective
Write a function that returns the nth Fibonacci number.

## Function Prototype
```c
int ft_fibonacci(int index);
```

## Beginner Explanation
- Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, ...
- If index < 0, return -1.
- Use recursion: fib(n) = fib(n-1) + fib(n-2).

## Example
```c
ft_fibonacci(0); // returns 0
ft_fibonacci(1); // returns 1
ft_fibonacci(5); // returns 5
ft_fibonacci(-1); // returns -1
```

## Steps
1. If index < 0, return -1.
2. If index == 0, return 0.
3. If index == 1, return 1.
4. Return ft_fibonacci(index - 1) + ft_fibonacci(index - 2).

## Manual Testing
Use the provided main.c to test different cases.
