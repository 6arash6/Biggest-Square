# ex05: ft_list_push_strs

## Objective
Create a linked list from an array of strings.

## Function Prototype
```c
t_list *ft_list_push_strs(int size, char **strs);
```

## Beginner Explanation
- Loop through the array of strings.
- Create a new element for each string.
- Link all elements together.

## Example
```c
char *arr[] = {"a", "b", "c"};
t_list *head = ft_list_push_strs(3, arr);
```

## Manual Testing
Use the provided main.c to test different cases.
