# ex16: ft_sorted_list_insert

## Objective
Insert an element into a sorted linked list.

## Function Prototype
```c
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)(void *, void *));
```

## Beginner Explanation
- Create a new element.
- Find the correct position using cmp.
- Insert the element.

## Example
```c
ft_sorted_list_insert(&head, &value, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
