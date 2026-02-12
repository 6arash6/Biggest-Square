# ex10: ft_strlcat

## Objective
Write a function that concatenates two strings with a size limit, and returns the total length the string would have had.

## Function Prototype
```c
unsigned int ft_strlcat(char *dest, const char *src, unsigned int size);
```

## Beginner Explanation
- Append src to dest, up to (size - 1) characters.
- Always null-terminate dest if size > 0.
- Return the length dest + src would have had if there was enough space.

## Example
```c
char dest[10] = "Hello";
unsigned int len = ft_strlcat(dest, "World", 10); // dest = "HelloWorl", len = 10
```

## Steps
1. Find the length of dest and src.
2. Append src to dest, up to (size - 1).
3. Null-terminate dest.
4. Return the total length dest + src.

## Manual Testing
Use the provided main.c to test different cases.
