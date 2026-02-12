# ex04: ft_list_push_back

## Objective
Add a new element to the end of a linked list.

## Function Prototype
```c
void ft_list_push_back(t_list **begin_list, void *data);
```

## Beginner Explanation
- Create a new element.
- Loop to the end of the list.
- Set the last element's next to the new element.

## Example
```c
ft_list_push_back(&head, &value);
```

## Manual Testing
Use the provided main.c to test different cases.
