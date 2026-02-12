# ex02: ft_print_rev_params

## Objective
Write a program that prints its parameters in reverse order, one per line.

## Beginner Explanation
- Use argv to access command-line parameters.
- Print each parameter in reverse order.

## Example
```
$ ./a.out hello world
world
hello
```

## Steps
1. Loop from argv[argc-1] down to argv[1].
2. Print each character.
3. Print newline after each parameter.

## Manual Testing
Compile and run with parameters to see them printed in reverse.
