# C03/ex04: ft_strrchr

## Function
`char *ft_strrchr(const char *s, int c);`

## Description
Finds the last occurrence of character `c` in string `s`. Returns a pointer to the last occurrence or NULL if not found.

## Example
```
ft_strrchr("Piscine42", 'i'); // Output: "ine42"
```

## Beginner Tips
- Use a loop to scan the string.
- Track the last position where `c` is found.
- Return NULL if not found.

## Testing
Run `sh test.sh` to compile and test automatically.
