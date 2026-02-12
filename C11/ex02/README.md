# ex02: ft_any

## Objective
Check if at least one element in a string array returns non-zero for function `f`.

## Function Prototype
```c
int ft_any(char **tab, int(*f)(char*));
```

## Beginner Explanation
- Loop through the array.
- Apply function `f` to each element.
- If any result is non-zero, return 1.
- Otherwise, return 0.

## Example
```c
int is_a(char *s) { return s[0] == 'a'; }
char *arr[] = {"bcd", "abc", "xyz", NULL};
int result = ft_any(arr, is_a); // result: 1
```

## Manual Testing
Use the provided main.c to test different cases.
