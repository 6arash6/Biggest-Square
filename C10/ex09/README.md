# ex09: ft_list_sort

## Objective
Write a function that sorts a linked list using cmp.

## Function Prototype
```c
void ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
```

## Beginner Explanation
- Use bubble sort to sort list.
- Swap data using cmp.

## Example
```c
ft_list_sort(&head, cmp);
```

## Steps
1. Loop through list.
2. Swap data if cmp > 0.
3. Repeat until sorted.

## Manual Testing
Use the provided main.c to test different cases.
