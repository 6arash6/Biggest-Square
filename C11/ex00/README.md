# ex00: ft_foreach

## Objective
Apply a function to each element of an integer array.

## Function Prototype
```c
void ft_foreach(int *tab, int length, void(*f)(int));
```

## Beginner Explanation
- Loop through the array.
- Call the function `f` for each element.

## Example
```c
void print(int n) { printf("%d ", n); }
int arr[] = {1, 2, 3};
ft_foreach(arr, 3, print); // Output: 1 2 3
```

## Manual Testing
Use the provided main.c to test different cases.
