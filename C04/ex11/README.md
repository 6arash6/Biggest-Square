# ex11: ft_strlcpy

## Objective
Write a function that copies a string into another, with a size limit, and returns the length of the source string.

## Function Prototype
```c
unsigned int ft_strlcpy(char *dest, const char *src, unsigned int size);
```

## Beginner Explanation
- The function copies up to (size - 1) characters from src to dest.
- It always null-terminates dest if size > 0.
- Returns the length of src.

## Example
```c
char dest[10];
unsigned int len = ft_strlcpy(dest, "Hello", 10); // dest = "Hello", len = 5
```

## Steps
1. Copy characters from src to dest, up to (size - 1).
2. Null-terminate dest.
3. Return the length of src.

## Manual Testing
Use the provided main.c to test different cases.
