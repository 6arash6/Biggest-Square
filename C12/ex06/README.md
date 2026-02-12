# ex06: ft_list_clear

## Objective
Free all elements of a linked list.

## Function Prototype
```c
void ft_list_clear(t_list **begin_list, void (*free_fct)(void *));
```

## Beginner Explanation
- Loop through the list.
- Free each element's data using free_fct.
- Free each element.
- Set head to NULL.

## Example
```c
ft_list_clear(&head, free);
```

## Manual Testing
Use the provided main.c to test different cases.
