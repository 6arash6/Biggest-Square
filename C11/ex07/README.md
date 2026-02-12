# ex07: ft_advanced_sort_string_tab

## Objective
Sort a null-terminated array of strings using a custom comparison function.

## Function Prototype
```c
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
```

## Beginner Explanation
- Use bubble sort to sort the array.
- Use the provided comparison function.
- Swap pointers, not string contents.

## Example
```c
int cmp(char *a, char *b) { return strcmp(a, b); }
char *arr[] = {"abc", "bcd", "acd", NULL};
ft_advanced_sort_string_tab(arr, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
