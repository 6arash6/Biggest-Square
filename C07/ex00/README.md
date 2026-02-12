# ex00: ft_strdup

## Objective
Write a function that duplicates a string using malloc.

## Function Prototype
```c
char *ft_strdup(const char *src);
```

## Beginner Explanation
- Find the length of src.
- Allocate memory for the duplicate.
- Copy each character.
- Null-terminate the duplicate.

## Example
```c
char *s = ft_strdup("Hello"); // s = "Hello"
```

## Steps
1. Find length of src.
2. Allocate memory.
3. Copy characters.
4. Null-terminate.

## Manual Testing
Use the provided main.c to test different cases.
