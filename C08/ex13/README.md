# ex13: ft_strcpy

## Objective
Write a function that copies src to dest.

## Function Prototype
```c
char *ft_strcpy(char *dest, const char *src);
```

## Beginner Explanation
- Copy each character from src to dest.
- Null-terminate dest.

## Example
```c
char dest[10];
ft_strcpy(dest, "Hello"); // dest = "Hello"
```

## Steps
1. Copy characters from src.
2. Null-terminate dest.
3. Return dest.

## Manual Testing
Use the provided main.c to test different cases.
