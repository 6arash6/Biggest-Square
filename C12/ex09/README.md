# ex09: ft_list_foreach

## Objective
Apply a function to each element's data in a linked list.

## Function Prototype
```c
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
```

## Beginner Explanation
- Loop through the list.
- Call the function `f` for each element's data.

## Example
```c
void print(void *data) { printf("%d ", *(int *)data); }
ft_list_foreach(head, print);
```

## Manual Testing
Use the provided main.c to test different cases.
