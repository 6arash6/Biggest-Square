# ex02: ft_ultimate_range

## Objective
Write a function that allocates and fills an array from min (inclusive) to max (exclusive), and returns its length.

## Function Prototype
```c
int ft_ultimate_range(int **range, int min, int max);
```

## Beginner Explanation
- Allocate an array of (max - min) integers.
- Fill array with values from min to max-1.
- Return length.
- If min >= max, set *range to NULL and return 0.

## Example
```c
int *arr;
int len = ft_ultimate_range(&arr, 3, 7); // arr = [3, 4, 5, 6], len = 4
```

## Steps
1. Check if min >= max, set *range to NULL, return 0.
2. Allocate memory.
3. Fill array.
4. Return length.

## Manual Testing
Use the provided main.c to test different cases.
