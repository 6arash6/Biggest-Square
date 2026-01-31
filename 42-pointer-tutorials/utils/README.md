# Utility Functions

## Overview
This directory contains helper functions commonly used in 42 school projects. These functions provide basic I/O functionality using only the `write()` system call from `<unistd.h>`.

## Available Functions

### ft_putchar
```c
void ft_putchar(char c);
```
Writes a single character to standard output.

**Parameters:**
- `c`: The character to print

**Example:**
```c
ft_putchar('A');  // Outputs: A
```

### ft_putstr
```c
void ft_putstr(char *str);
```
Writes a string to standard output.

**Parameters:**
- `str`: Pointer to a null-terminated string

**Example:**
```c
ft_putstr("Hello, 42!");  // Outputs: Hello, 42!
```

### ft_putnbr
```c
void ft_putnbr(int n);
```
Writes an integer to standard output. Handles negative numbers and INT_MIN (-2147483648).

**Parameters:**
- `n`: The integer to print

**Example:**
```c
ft_putnbr(42);      // Outputs: 42
ft_putnbr(-123);    // Outputs: -123
```

## How to Use

### Standalone Compilation
To use these functions in your programs, you need to compile them together:

```bash
# Example with ft_putchar
gcc -Wall -Wextra -Werror ft_putchar.c your_program.c -o program

# Example with ft_putstr (needs ft_putchar)
gcc -Wall -Wextra -Werror ft_putchar.c ft_putstr.c your_program.c -o program

# Example with ft_putnbr (needs ft_putchar)
gcc -Wall -Wextra -Werror ft_putchar.c ft_putnbr.c your_program.c -o program
```

### In Your Code
Add the function prototype at the top of your file:

```c
#include <unistd.h>

void ft_putchar(char c);  // If using ft_putchar

int main(void)
{
    ft_putchar('4');
    ft_putchar('2');
    ft_putchar('\n');
    return (0);
}
```

## Why These Functions?

During 42 exams and piscine, you're typically **not allowed** to use:
- `printf()` from `<stdio.h>`
- `puts()` from `<stdio.h>`
- Most standard library functions

You **are allowed** to use:
- `write()` from `<unistd.h>`
- `malloc()` and `free()` from `<stdlib.h>` (in some exams)
- Basic functions you write yourself

That's why we create these utility functions - they provide similar functionality to `printf()` but use only `write()`.

## 42 Exam Tips

### Finding Allowed Functions
During exams, use the `man` command to check what functions are available:

```bash
# Search for string-related functions
man -k "string"

# Search for memory-related functions
man -k "memory"

# Get details about write function
man 2 write

# Get details about a library function (section 3)
man 3 strlen
```

### Understanding man Sections
- Section 1: User commands
- Section 2: System calls (like write, read, open)
- Section 3: Library functions (like strlen, malloc)

### What's Usually Allowed
Check your exam instructions, but typically:
- ✅ write
- ✅ malloc, free
- ✅ Your own helper functions
- ❌ printf, scanf
- ❌ puts, putchar (from stdio.h)
- ❌ strlen, strcpy, strcmp (unless you write them)

## Notes
- All functions follow the 42 Norminette coding standard
- Functions use tabs for indentation
- Variable declarations are at the top of functions
- No function exceeds 25 lines
- Return statements use parentheses: `return (0);`
