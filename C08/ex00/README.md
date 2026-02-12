# ex00: ft_create_array

## Objective
Write a function that creates an array of size filled with character c.

## Function Prototype
```c
char *ft_create_array(unsigned int size, char c);
```

## Beginner Explanation
- Allocate memory for size characters plus null terminator.
- Fill array with c.
- Null-terminate.

## Example
```c
char *arr = ft_create_array(5, 'A'); // arr = "AAAAA"
```

## Steps
1. Allocate memory.
2. Fill array with c.
3. Null-terminate.
4. Return pointer.

## Manual Testing
Use the provided main.c to test different cases.
