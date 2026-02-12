# ex09: ft_str_to_lower

## Objective
Write a function that converts all uppercase letters in a string to lowercase.

## Function Prototype
```c
char *ft_str_to_lower(char *str);
```

## Beginner Explanation
- The function changes each uppercase letter (A-Z) to lowercase (a-z).
- It modifies the string in place and returns the same pointer.

## Example
```c
char s[] = "HELLO WORLD!";
ft_str_to_lower(s); // s becomes "hello world!"
```

## Steps
1. Loop through each character in the string.
2. If the character is between 'A'-'Z', add 32 to convert to lowercase.
3. Continue until end of string.

## Manual Testing
Use the provided main.c to test different cases.
