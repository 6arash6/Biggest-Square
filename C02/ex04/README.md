# C02/ex04: ft_str_is_lowercase

## Function
`int ft_str_is_lowercase(const char *str);`

## Description
Checks if the string contains only lowercase alphabetic characters (a-z). Returns 1 if true, 0 otherwise.

## Example
```
ft_str_is_lowercase("piscine"); // Output: 1
ft_str_is_lowercase("Piscine"); // Output: 0
```

## Beginner Tips
- Use a loop to check each character.
- Return 0 if any character is not lowercase.
- Return 1 if all are lowercase.

## Testing
Run `sh test.sh` to compile and test automatically.
