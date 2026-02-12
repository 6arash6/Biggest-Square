# ex07: ft_strncmp

## Objective
Write a function that compares two strings up to n characters.

## Function Prototype
```c
int ft_strncmp(const char *s1, const char *s2, unsigned int n);
```

## Beginner Explanation
- Compare up to n characters.
- Return difference of first non-matching character.
- If equal, return 0.

## Example
```c
ft_strncmp("abc", "abd", 2); // 0
ft_strncmp("abc", "abd", 3); // -1
```

## Steps
1. Loop up to n characters.
2. Compare characters.
3. Return difference.

## Manual Testing
Use the provided main.c to test different cases.
