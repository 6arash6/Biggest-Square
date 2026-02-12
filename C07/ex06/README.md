# ex06: ft_sort_int_tab

## Objective
Write a function that sorts an array of integers in ascending order.

## Function Prototype
```c
void ft_sort_int_tab(int *tab, int size);
```

## Beginner Explanation
- Use bubble sort to sort the array.
- Compare and swap adjacent elements.

## Example
```c
int arr[] = {4, 3, 2, 1};
ft_sort_int_tab(arr, 4); // arr = [1, 2, 3, 4]
```

## Steps
1. Loop through array.
2. Compare and swap elements.
3. Repeat until sorted.

## Manual Testing
Use the provided main.c to test different cases.
