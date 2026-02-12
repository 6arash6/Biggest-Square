# ex11: ft_strncat

## Objective
Write a function that concatenates n characters from src to dest.

## Function Prototype
```c
char *ft_strncat(char *dest, const char *src, unsigned int n);
```

## Beginner Explanation
- Find the length of dest.
- Copy up to n characters from src to dest.
- Null-terminate.

## Example
```c
char dest[20] = "Hello";
ft_strncat(dest, "World", 3); // dest = "HelloWor"
```

## Steps
1. Find length of dest.
2. Copy up to n characters from src.
3. Null-terminate.

## Manual Testing
Use the provided main.c to test different cases.
