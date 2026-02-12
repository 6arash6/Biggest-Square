# C03/ex00: ft_strcmp

## Function
`int ft_strcmp(const char *s1, const char *s2);`

## Description
Compares two strings lexicographically. Returns 0 if equal, a positive value if s1 > s2, or a negative value if s1 < s2.

## Example
```
ft_strcmp("Piscine", "Piscine"); // Output: 0
ft_strcmp("Piscine", "42"); // Output: >0
ft_strcmp("42", "Piscine"); // Output: <0
```

## Beginner Tips
- Use a loop to compare each character.
- Return the difference at the first mismatch.
- Return 0 if all characters match.

## Testing
Run `sh test.sh` to compile and test automatically.
