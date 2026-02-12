# ex10: ft_list_foreach_if

## Objective
Apply a function to each element's data in a linked list if a condition is met.

## Function Prototype
```c
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)(void *, void *));
```

## Beginner Explanation
- Loop through the list.
- If cmp(element->data, data_ref) == 0, call f on element->data.

## Example
```c
void print(void *data) { printf("%d ", *(int *)data); }
int cmp(void *a, void *b) { return (*(int *)a - *(int *)b); }
ft_list_foreach_if(head, print, &value, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
