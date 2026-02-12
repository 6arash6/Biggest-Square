# ex04: ft_is_sort

## Objective
Check if an integer array is sorted using a comparison function.

## Function Prototype
```c
int ft_is_sort(int *tab, int length, int(*f)(int, int));
```

## Beginner Explanation
- Loop through the array.
- Use the comparison function to check order.
- Return 1 if sorted, 0 otherwise.

## Example
```c
int cmp(int a, int b) { return a - b; }
int arr[] = {1, 2, 3};
int result = ft_is_sort(arr, 3, cmp); // result: 1
```

## Manual Testing
Use the provided main.c to test different cases.
