# ex12: ft_strncpy

## Objective
Write a function that copies n characters from src to dest.

## Function Prototype
```c
char *ft_strncpy(char *dest, const char *src, unsigned int n);
```

## Beginner Explanation
- Copy up to n characters from src to dest.
- If src is shorter than n, fill dest with '\0'.

## Example
```c
char dest[10];
ft_strncpy(dest, "Hello", 10); // dest = "Hello\0\0\0\0\0"
```

## Steps
1. Copy up to n characters from src.
2. Fill rest with '\0'.
3. Return dest.

## Manual Testing
Use the provided main.c to test different cases.
