# ex10: ft_strcapitalize

## Objective
Write a function that capitalizes the first letter of each word in a string and makes the rest lowercase.

## Function Prototype
```c
char *ft_strcapitalize(char *str);
```

## Beginner Explanation
- The function changes the first letter of each word to uppercase.
- All other letters in the word are changed to lowercase.
- Words are separated by non-alphanumeric characters.

## Example
```c
char s[] = "hello world! 42piscine";
ft_strcapitalize(s); // s becomes "Hello World! 42Piscine"
```

## Steps
1. Loop through each character in the string.
2. If it's the start of a word, capitalize.
3. If it's inside a word, make lowercase.
4. Words are separated by non-alphanumeric characters.

## Manual Testing
Use the provided main.c to test different cases.
