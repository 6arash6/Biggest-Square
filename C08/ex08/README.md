# ex08: ft_strstr

## Objective
Write a function that locates a substring in a string.

## Function Prototype
```c
char *ft_strstr(const char *haystack, const char *needle);
```

## Beginner Explanation
- Search for needle in haystack.
- Return pointer to first occurrence, or NULL if not found.

## Example
```c
ft_strstr("Hello World", "World"); // returns pointer to "World"
```

## Steps
1. Loop through haystack.
2. Compare with needle.
3. Return pointer if found.

## Manual Testing
Use the provided main.c to test different cases.
