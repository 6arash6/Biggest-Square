# ex11: ft_list_find

## Objective
Find the first element in a linked list matching a reference value.

## Function Prototype
```c
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *));
```

## Beginner Explanation
- Loop through the list.
- If cmp(element->data, data_ref) == 0, return element.
- If not found, return NULL.

## Example
```c
t_list *found = ft_list_find(head, &value, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
