# ex04: ft_ultimate_div_mod

**Goal:** Divide and modulo two integers, store results in the addresses pointed to by pointers.

- **Prototype:** `void ft_ultimate_div_mod(int *a, int *b);`
- **Allowed functions:** None.
- **How it works:**
  - Divides `*a` by `*b`, stores result in `*a`.
  - Stores remainder in `*b`.

**Example usage:**
```c
int a = 10, b = 3;
ft_ultimate_div_mod(&a, &b);
// a is 3, b is 1
```
