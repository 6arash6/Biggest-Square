# ex03: ft_str_is_alpha

## Objective
Write a function that returns 1 if the string passed as a parameter contains only alphabetical characters, and 0 otherwise.

## Function Prototype
```c
int ft_str_is_alpha(const char *str);
```

## Beginner Explanation
- The function checks each character in the string.
- If all characters are letters (A-Z or a-z), it returns 1.
- If any character is not a letter, it returns 0.
- An empty string should return 1.

## Example
```c
ft_str_is_alpha("Hello")   // returns 1
ft_str_is_alpha("Hello123") // returns 0
ft_str_is_alpha("")        // returns 1
```

## Steps
1. Loop through each character in the string.
2. Check if the character is between 'A'-'Z' or 'a'-'z'.
3. If not, return 0.
4. If loop finishes, return 1.

## Manual Testing
Use the provided main.c to test different cases.
