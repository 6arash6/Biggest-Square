# ex01: ft_list_push_front

## Objective
Add a new element to the front of a linked list.

## Function Prototype
```c
void ft_list_push_front(t_list **begin_list, void *data);
```

## Beginner Explanation
- Create a new element.
- Set its next to the current head.
- Update the head pointer.

## Example
```c
ft_list_push_front(&head, &value);
```

## Manual Testing
Use the provided main.c to test different cases.
