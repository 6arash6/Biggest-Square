# C03/ex01: ft_strncmp

## Function
`int ft_strncmp(const char *s1, const char *s2, unsigned int n);`

## Description
Compares up to `n` characters of two strings lexicographically. Returns 0 if equal, a positive value if s1 > s2, or a negative value if s1 < s2.

## Example
```
ft_strncmp("Piscine", "Piscine", 4); // Output: 0
ft_strncmp("Piscine", "42", 2); // Output: >0
ft_strncmp("42", "Piscine", 2); // Output: <0
```

## Beginner Tips
- Use a loop to compare up to `n` characters.
- Return the difference at the first mismatch.
- Return 0 if all compared characters match.

## Testing
Run `sh test.sh` to compile and test automatically.
