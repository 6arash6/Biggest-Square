# ex03: ft_count_if

## Objective
Count the number of elements in a string array for which function `f` returns non-zero.

## Function Prototype
```c
int ft_count_if(char **tab, int length, int(*f)(char*));
```

## Beginner Explanation
- Loop through the array.
- Apply function `f` to each element.
- Count how many times the result is non-zero.

## Example
```c
int is_a(char *s) { return s[0] == 'a'; }
char *arr[] = {"abc", "bcd", "acd"};
int result = ft_count_if(arr, 3, is_a); // result: 2
```

## Manual Testing
Use the provided main.c to test different cases.
