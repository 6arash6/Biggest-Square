# ex07: ft_str_is_printable

## Objective
Write a function that returns 1 if the string passed as a parameter contains only printable characters, and 0 otherwise.

## Function Prototype
```c
int ft_str_is_printable(const char *str);
```

## Beginner Explanation
- The function checks each character in the string.
- If all characters are printable (ASCII 32 to 126), it returns 1.
- If any character is not printable, it returns 0.
- An empty string should return 1.

## Example
```c
ft_str_is_printable("Hello!")   // returns 1
ft_str_is_printable("Hello\n")  // returns 0
ft_str_is_printable("")         // returns 1
```

## Steps
1. Loop through each character in the string.
2. Check if the character is between ASCII 32 and 126.
3. If not, return 0.
4. If loop finishes, return 1.

## Manual Testing
Use the provided main.c to test different cases.
