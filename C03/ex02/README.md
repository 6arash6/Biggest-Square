# C03/ex02: ft_strcat

## Function
`char *ft_strcat(char *dest, const char *src);`

## Description
Appends the string `src` to the end of `dest`. Returns `dest`.

## Example
```
char dest[100] = "Piscine";
ft_strcat(dest, "42");
printf("%s\n", dest); // Output: Piscine42
```

## Beginner Tips
- Find the end of `dest` before appending.
- Use a loop to copy each character from `src`.
- Don't forget the null terminator.

## Testing
Run `sh test.sh` to compile and test automatically.
