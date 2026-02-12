# ex02: ft_putnbr

## Objective
Write a function that prints an integer to standard output.

## Function Prototype
```c
void ft_putnbr(int nb);
```

## Beginner Explanation
- Print digits recursively.
- Handle negative numbers.
- Special case for INT_MIN.

## Example
```c
ft_putnbr(42); // prints 42
ft_putnbr(-42); // prints -42
```

## Steps
1. Handle INT_MIN.
2. Handle negative.
3. Print digits recursively.

## Manual Testing
Use the provided main.c to test different cases.
