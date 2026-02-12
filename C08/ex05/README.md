# ex05: ft_strcat

## Objective
Write a function that concatenates src to dest.

## Function Prototype
```c
char *ft_strcat(char *dest, const char *src);
```

## Beginner Explanation
- Find the length of dest.
- Copy src to the end of dest.
- Null-terminate.

## Example
```c
char dest[20] = "Hello";
ft_strcat(dest, "World"); // dest = "HelloWorld"
```

## Steps
1. Find length of dest.
2. Copy src to dest.
3. Null-terminate.

## Manual Testing
Use the provided main.c to test different cases.
