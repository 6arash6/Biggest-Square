# ex00: ft_putchar

**Goal:** Write a function that displays a character.

- **Prototype:** `void ft_putchar(char c);`
- **Allowed functions:** Only `write`.
- **How it works:**
  - The function takes a character as input.
  - It uses `write(1, &c, 1);` to print the character to standard output.

**Example usage:**
```c
ft_putchar('A'); // Output: A
```
