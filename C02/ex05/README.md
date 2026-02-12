# C02/ex05: ft_str_is_uppercase

## Function
`int ft_str_is_uppercase(const char *str);`

## Description
Checks if the string contains only uppercase alphabetic characters (A-Z). Returns 1 if true, 0 otherwise.

## Example
```
ft_str_is_uppercase("PISCINE"); // Output: 1
ft_str_is_uppercase("Piscine"); // Output: 0
```

## Beginner Tips
- Use a loop to check each character.
- Return 0 if any character is not uppercase.
- Return 1 if all are uppercase.

## Testing
Run `sh test.sh` to compile and test automatically.
