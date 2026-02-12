# ex05: ft_str_is_lowercase

## Objective
Write a function that returns 1 if the string passed as a parameter contains only lowercase alphabetical characters, and 0 otherwise.

## Function Prototype
```c
int ft_str_is_lowercase(const char *str);
```

## Beginner Explanation
- The function checks each character in the string.
- If all characters are lowercase letters (a-z), it returns 1.
- If any character is not a lowercase letter, it returns 0.
- An empty string should return 1.

## Example
```c
ft_str_is_lowercase("hello")   // returns 1
ft_str_is_lowercase("Hello")   // returns 0
ft_str_is_lowercase("")        // returns 1
```

## Steps
1. Loop through each character in the string.
2. Check if the character is between 'a'-'z'.
3. If not, return 0.
4. If loop finishes, return 1.

## Manual Testing
Use the provided main.c to test different cases.
