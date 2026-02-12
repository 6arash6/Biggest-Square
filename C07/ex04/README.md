# ex04: ft_max

## Objective
Write a function that returns the maximum value in an array of integers.

## Function Prototype
```c
int ft_max(int *arr, int size);
```

## Beginner Explanation
- Loop through the array.
- Track the maximum value.
- Return max.

## Example
```c
int arr[] = {1, 2, 3, 4};
int m = ft_max(arr, 4); // m = 4
```

## Steps
1. Initialize max to arr[0].
2. Loop through array.
3. Update max if arr[i] > max.
4. Return max.

## Manual Testing
Use the provided main.c to test different cases.
