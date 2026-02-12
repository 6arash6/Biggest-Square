# ex05: ft_min

## Objective
Write a function that returns the minimum value in an array of integers.

## Function Prototype
```c
int ft_min(int *arr, int size);
```

## Beginner Explanation
- Loop through the array.
- Track the minimum value.
- Return min.

## Example
```c
int arr[] = {1, 2, 3, 4};
int m = ft_min(arr, 4); // m = 1
```

## Steps
1. Initialize min to arr[0].
2. Loop through array.
3. Update min if arr[i] < min.
4. Return min.

## Manual Testing
Use the provided main.c to test different cases.
