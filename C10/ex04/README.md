# ex04: ft_list_clear

## Objective
Write a function that clears a linked list and frees memory.

## Function Prototype
```c
void ft_list_clear(t_list **begin_list);
```

## Beginner Explanation
- Loop through the list.
- Free each node.
- Set begin_list to NULL.

## Example
```c
ft_list_clear(&head);
```

## Steps
1. Loop through list.
2. Free nodes.
3. Set begin_list to NULL.

## Manual Testing
Use the provided main.c to test different cases.
