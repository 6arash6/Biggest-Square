# C03/ex05: ft_strstr

## Function
`char *ft_strstr(const char *haystack, const char *needle);`

## Description
Finds the first occurrence of `needle` in `haystack`. Returns a pointer to the start of `needle` or NULL if not found.

## Example
```
ft_strstr("Piscine42", "42"); // Output: "42"
```

## Beginner Tips
- Use a loop to scan the string.
- Check for a match at each position.
- Return NULL if not found.

## Testing
Run `sh test.sh` to compile and test automatically.
