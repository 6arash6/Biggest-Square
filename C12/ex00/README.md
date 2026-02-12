# ex00: ft_create_elem

## Objective
Create a new linked list element (t_list) and assign data.

## Function Prototype
```c
t_list *ft_create_elem(void *data);
```

## Beginner Explanation
- Allocate memory for a new element.
- Set its data to the argument.
- Set next to NULL.

## Example
```c
t_list *elem = ft_create_elem(&value);
```

## Manual Testing
Use the provided main.c to test different cases.
