# ex00: ft_ft

**Goal:** Store the value 42 in the int pointed to by the parameter.

- **Prototype:** `void ft_ft(int *nbr);`
- **Allowed functions:** None.
- **How it works:**
  - Takes a pointer to an int as a parameter.
  - Sets the value at that address to 42 using `*nbr = 42;`.

**Example usage:**
```c
int x;
ft_ft(&x);
// x is now 42
```
