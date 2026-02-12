# C03/ex03: ft_strlcat

## Function
`unsigned int ft_strlcat(char *dest, const char *src, unsigned int size);`

## Description
Appends `src` to `dest` up to `size` bytes, returning the total length of the string it tried to create.

## Example
```
char dest[100] = "Piscine";
ft_strlcat(dest, "42", 100); // dest: "Piscine42", returns 9
```

## Beginner Tips
- Find the length of `dest` and `src`.
- Append characters from `src` to `dest` without exceeding `size - 1`.
- Always null-terminate.

## Testing
Run `sh test.sh` to compile and test automatically.
