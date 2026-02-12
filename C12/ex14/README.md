# ex14: ft_list_sort

## Objective
Sort a linked list using a comparison function.

## Function Prototype
```c
void ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
```

## Beginner Explanation
- Use bubble sort to sort the list.
- Swap data using cmp.

## Example
```c
ft_list_sort(&head, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
