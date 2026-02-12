# ex01: ft_strjoin

## Objective
Write a function that joins two strings into a new string.

## Function Prototype
```c
char *ft_strjoin(const char *s1, const char *s2);
```

## Beginner Explanation
- Find the length of both strings.
- Allocate memory for the joined string.
- Copy both strings into the new memory.
- Null-terminate.

## Example
```c
char *s = ft_strjoin("Hello", "World"); // s = "HelloWorld"
```

## Steps
1. Find length of s1 and s2.
2. Allocate memory.
3. Copy s1 and s2.
4. Null-terminate.

## Manual Testing
Use the provided main.c to test different cases.
