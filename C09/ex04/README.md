# ex04: ft_itoa

## Objective
Write a function that converts an integer to a string.

## Function Prototype
```c
char *ft_itoa(int n);
```

## Beginner Explanation
- Find length of number.
- Allocate memory.
- Fill string with digits.
- Handle negative.

## Example
```c
char *s = ft_itoa(42); // s = "42"
char *s2 = ft_itoa(-42); // s2 = "-42"
```

## Steps
1. Find length.
2. Allocate memory.
3. Fill string with digits.
4. Handle negative.

## Manual Testing
Use the provided main.c to test different cases.
