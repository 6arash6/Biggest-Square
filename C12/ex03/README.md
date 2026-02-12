# ex03: ft_list_last

## Objective
Return the last element of a linked list.

## Function Prototype
```c
t_list *ft_list_last(t_list *begin_list);
```

## Beginner Explanation
- Loop through the list.
- Return the last element (where next is NULL).

## Example
```c
t_list *last = ft_list_last(head);
```

## Manual Testing
Use the provided main.c to test different cases.
