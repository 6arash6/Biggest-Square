# C02/ex03: ft_str_is_numeric

## Function
`int ft_str_is_numeric(const char *str);`

## Description
Checks if the string contains only numeric characters (0-9). Returns 1 if true, 0 otherwise.

## Example
```
ft_str_is_numeric("123456"); // Output: 1
ft_str_is_numeric("42Piscine"); // Output: 0
```

## Beginner Tips
- Use a loop to check each character.
- Return 0 if any character is not a digit.
- Return 1 if all are digits.

## Testing
Run `sh test.sh` to compile and test automatically.
