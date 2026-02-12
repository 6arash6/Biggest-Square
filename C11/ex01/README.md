# ex01: ft_map

## Objective
Apply a function to each element of an integer array and return a new array with the results.

## Function Prototype
```c
int *ft_map(int *tab, int length, int(*f)(int));
```

## Beginner Explanation
- Allocate a new array.
- Loop through the input array.
- Apply function `f` to each element and store the result in the new array.

## Example
```c
int square(int n) { return n * n; }
int arr[] = {1, 2, 3};
int *result = ft_map(arr, 3, square); // result: [1, 4, 9]
```

## Manual Testing
Use the provided main.c to test different cases.
