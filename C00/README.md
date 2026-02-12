# C00 Beginner Guide

This README explains each exercise in C00, the requirements, and the solution approach for beginners.

## ex00: ft_putchar
- **Goal:** Write a function that displays a character.
- **Prototype:** `void ft_putchar(char c);`
- **Allowed:** Only `write`.
- **How:** Use `write(1, &c, 1);` to print the character to standard output.

## ex01: ft_print_alphabet
- **Goal:** Print the lowercase alphabet in order.
- **Prototype:** `void ft_print_alphabet(void);`
- **How:** Use a loop from 'a' to 'z', printing each letter with `write`.

## ex02: ft_print_reverse_alphabet
- **Goal:** Print the lowercase alphabet in reverse order.
- **Prototype:** `void ft_print_reverse_alphabet(void);`
- **How:** Loop from 'z' down to 'a', printing each letter.

## ex03: ft_print_numbers
- **Goal:** Print all digits from 0 to 9.
- **Prototype:** `void ft_print_numbers(void);`
- **How:** Loop from '0' to '9', printing each digit.

## ex04: ft_is_negative
- **Goal:** Print 'N' if the number is negative, 'P' otherwise.
- **Prototype:** `void ft_is_negative(int n);`
- **How:** Use an if/else to check if n < 0, print 'N' or 'P'.

## ex05: ft_print_comb
- **Goal:** Print all unique combinations of three different digits in ascending order.
- **Prototype:** `void ft_print_comb(void);`
- **How:** Use three nested loops for a, b, c. Print only if a < b < c. Add ", " except after the last.

## ex06: ft_print_comb2
- **Goal:** Print all combinations of two different two-digit numbers (00 01 ... 98 99).
- **Prototype:** `void ft_print_comb2(void);`
- **How:** Use two loops for i and j (i < j). Print each pair as two two-digit numbers.

## ex07: ft_putnbr
- **Goal:** Print an integer (handle negatives and INT_MIN).
- **Prototype:** `void ft_putnbr(int nb);`
- **How:** Use recursion to print each digit. Handle negatives and INT_MIN edge case.

## ex08: ft_print_combn
- **Goal:** Print all unique combinations of n digits in ascending order (n: 1-9).
- **Prototype:** `void ft_print_combn(int n);`
- **How:** Use an array to store the current combination. Increment and print as needed.

---

### How to Compile and Test
For each exercise:
```bash
cc -Wall -Wextra -Werror <file.c>
./a.out
```

- Only use allowed functions (usually just `write`).
- No main() unless the subject asks for it.
- Follow 42 Norm for formatting and file naming.

---

If you get stuck, read the code comments and try to understand each step. Practice writing and compiling small C programs to build confidence!
