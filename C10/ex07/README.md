# ex07: ft_list_remove_if

## Objective
Write a function that removes elements from a linked list if they match data_ref.

## Function Prototype
```c
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *));
```

## Beginner Explanation
- Loop through the list.
- Remove nodes matching data_ref.
- Use cmp function to compare.

## Example
```c
ft_list_remove_if(&head, data_ref, cmp);
```

## Steps
1. Loop through list.
2. Remove matching nodes.
3. Free memory.

## Manual Testing
Use the provided main.c to test different cases.
