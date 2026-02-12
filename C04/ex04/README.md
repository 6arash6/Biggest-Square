# ex04: ft_str_is_numeric

## Objective
Write a function that returns 1 if the string passed as a parameter contains only numeric characters, and 0 otherwise.

## Function Prototype
```c
int ft_str_is_numeric(const char *str);
```

## Beginner Explanation
- The function checks each character in the string.
- If all characters are digits (0-9), it returns 1.
- If any character is not a digit, it returns 0.
- An empty string should return 1.

## Example
```c
ft_str_is_numeric("12345")   // returns 1
ft_str_is_numeric("123abc")  // returns 0
ft_str_is_numeric("")        // returns 1
```

## Steps
1. Loop through each character in the string.
2. Check if the character is between '0'-'9'.
3. If not, return 0.
4. If loop finishes, return 1.

## Manual Testing
Use the provided main.c to test different cases.
