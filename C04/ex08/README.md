# ex08: ft_str_to_upper

## Objective
Write a function that converts all lowercase letters in a string to uppercase.

## Function Prototype
```c
char *ft_str_to_upper(char *str);
```

## Beginner Explanation
- The function changes each lowercase letter (a-z) to uppercase (A-Z).
- It modifies the string in place and returns the same pointer.

## Example
```c
char s[] = "Hello World!";
ft_str_to_upper(s); // s becomes "HELLO WORLD!"
```

## Steps
1. Loop through each character in the string.
2. If the character is between 'a'-'z', subtract 32 to convert to uppercase.
3. Continue until end of string.

## Manual Testing
Use the provided main.c to test different cases.
