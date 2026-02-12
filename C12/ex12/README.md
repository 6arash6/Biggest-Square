# ex12: ft_list_remove_if

## Objective
Remove elements from a linked list if their data matches a reference value.

## Function Prototype
```c
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *));
```

## Beginner Explanation
- Loop through the list.
- If cmp(element->data, data_ref) == 0, free the element's data and remove the element.
- Update the head pointer as needed.

## Example
```c
ft_list_remove_if(&head, &value, cmp, free);
```

## Manual Testing
Use the provided main.c to test different cases.
