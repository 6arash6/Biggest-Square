# C02/ex00: ft_strcpy

## Function
`char *ft_strcpy(char *dest, const char *src);`

## Description
Copies the string pointed to by `src` (including the null terminator) to the array pointed to by `dest`. Returns `dest`.

## Example
```
char dest[100];
ft_strcpy(dest, "Piscine42");
printf("%s\n", dest); // Output: Piscine42
```

## Beginner Tips
- Use a loop to copy each character.
- Don't forget to copy the null terminator (`'\0'`).
- Make sure `dest` is large enough to hold `src`.

## Testing
Run `sh test.sh` to compile and test automatically.
