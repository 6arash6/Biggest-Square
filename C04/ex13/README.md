# ex13: ft_str_non_printable

## Objective
Write a function that prints a string, replacing non-printable characters with their hexadecimal value prefixed by a backslash.

## Function Prototype
```c
void ft_str_non_printable(const char *str);
```

## Beginner Explanation
- The function prints each character in the string.
- If a character is not printable (ASCII < 32 or > 126), it prints its hex value with a backslash.
- Otherwise, it prints the character as is.

## Example
```c
ft_str_non_printable("Hello\nWorld"); // prints: Hello\0aWorld
```

## Steps
1. Loop through each character in the string.
2. If not printable, print backslash and hex value.
3. Else, print character.

## Manual Testing
Use the provided main.c to test different cases.
