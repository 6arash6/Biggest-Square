# ex07: ft_list_at

## Objective
Return the element at a specific index in a linked list.

## Function Prototype
```c
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
```

## Beginner Explanation
- Loop through the list.
- Return the element at the given index.
- If index is out of bounds, return NULL.

## Example
```c
t_list *elem = ft_list_at(head, 2);
```

## Manual Testing
Use the provided main.c to test different cases.
