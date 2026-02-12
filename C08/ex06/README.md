# ex06: ft_strcmp

## Objective
Write a function that compares two strings.

## Function Prototype
```c
int ft_strcmp(const char *s1, const char *s2);
```

## Beginner Explanation
- Compare characters of s1 and s2.
- Return difference of first non-matching character.
- If equal, return 0.

## Example
```c
ft_strcmp("abc", "abc"); // 0
ft_strcmp("abc", "abd"); // -1
ft_strcmp("abc", "ab"); // 'c' - '\0'
```

## Steps
1. Loop through both strings.
2. Compare characters.
3. Return difference.

## Manual Testing
Use the provided main.c to test different cases.
