# ex03: ft_strtrim

## Objective
Write a function that trims leading and trailing whitespace from a string.

## Function Prototype
```c
char *ft_strtrim(const char *str);
```

## Beginner Explanation
- Find the first and last non-whitespace character.
- Allocate memory for trimmed string.
- Copy trimmed part.
- Null-terminate.

## Example
```c
char *s = ft_strtrim("  Hello World  "); // s = "Hello World"
```

## Steps
1. Find start and end indices.
2. Allocate memory.
3. Copy trimmed part.
4. Null-terminate.

## Manual Testing
Use the provided main.c to test different cases.
