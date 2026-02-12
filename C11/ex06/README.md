# ex06: ft_sort_string_tab

## Objective
Sort a null-terminated array of strings in ASCII order.

## Function Prototype
```c
void ft_sort_string_tab(char **tab);
```

## Beginner Explanation
- Use bubble sort to sort the array.
- Swap pointers, not string contents.

## Example
```c
char *arr[] = {"abc", "bcd", "acd", NULL};
ft_sort_string_tab(arr);
```

## Manual Testing
Use the provided main.c to test different cases.
