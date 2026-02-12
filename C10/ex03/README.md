# ex03: ft_list_push_back

## Objective
Write a function that adds a new element at the end of a linked list.

## Function Prototype
```c
t_list *ft_list_push_back(t_list **begin_list, void *data);
```

## Beginner Explanation
- Allocate a new node.
- Set its data and next pointer.
- Add to end of list.

## Example
```c
t_list *head = NULL;
ft_list_push_back(&head, data);
```

## Steps
1. Allocate new node.
2. Set data and next.
3. Add to end.

## Manual Testing
Use the provided main.c to test different cases.
