# C02/ex01: ft_strncpy

## Function
`char *ft_strncpy(char *dest, const char *src, unsigned int n);`

## Description
Copies up to `n` characters from `src` to `dest`. If `src` is shorter than `n`, the remainder of `dest` is filled with null bytes. Returns `dest`.

## Example
```
char dest[100];
ft_strncpy(dest, "Piscine42", 4);
printf("%s\n", dest); // Output: Pisc
```

## Beginner Tips
- Use a loop to copy up to `n` characters.
- Fill the rest of `dest` with `\0` if `src` is shorter than `n`.
- Make sure `dest` is large enough.

## Testing
Run `sh test.sh` to compile and test automatically.
