# ex02: ft_strsplit

## Objective
Write a function that splits a string into an array of strings using a separator.

## Function Prototype
```c
char **ft_strsplit(const char *str, char sep);
```

## Beginner Explanation
- Count the number of words separated by sep.
- Allocate memory for each word.
- Fill array with words.
- Null-terminate the array.

## Example
```c
char **arr = ft_strsplit("a,b,c", ','); // arr = ["a", "b", "c", NULL]
```

## Steps
1. Count words.
2. Allocate memory for array.
3. Allocate memory for each word.
4. Fill array.
5. Null-terminate.

## Manual Testing
Use the provided main.c to test different cases.
