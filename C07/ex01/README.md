# ex01: ft_range

## Objective
Write a function that creates an array of integers from min (inclusive) to max (exclusive).

## Function Prototype
```c
int *ft_range(int min, int max);
```

## Beginner Explanation
- Allocate an array of (max - min) integers.
- Fill array with values from min to max-1.
- Return pointer to array.

## Example
```c
int *arr = ft_range(3, 7); // arr = [3, 4, 5, 6]
```

## Steps
1. Check if min >= max, return NULL.
2. Allocate memory.
3. Fill array.
4. Return pointer.

## Manual Testing
Use the provided main.c to test different cases.
