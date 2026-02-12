# ex00: ft_list_push_front

## Objective
Write a function that adds a new element at the beginning of a linked list.

## Function Prototype
```c
t_list *ft_list_push_front(t_list **begin_list, void *data);
```

## Beginner Explanation
- Allocate a new node.
- Set its data and next pointer.
- Update begin_list to point to new node.

## Example
```c
t_list *head = NULL;
ft_list_push_front(&head, data);
```

## Steps
1. Allocate new node.
2. Set data and next.
3. Update begin_list.

## Manual Testing
Use the provided main.c to test different cases.
