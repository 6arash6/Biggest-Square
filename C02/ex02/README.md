# C02/ex02: ft_str_is_alpha

## Function
`int ft_str_is_alpha(const char *str);`

## Description
Checks if the string contains only alphabetic characters (A-Z, a-z). Returns 1 if true, 0 otherwise.

## Example
```
ft_str_is_alpha("Piscine"); // Output: 1
ft_str_is_alpha("42Piscine"); // Output: 0
```

## Beginner Tips
- Use a loop to check each character.
- Return 0 if any character is not alphabetic.
- Return 1 if all are alphabetic.

## Testing
Run `sh test.sh` to compile and test automatically.
