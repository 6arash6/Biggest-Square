# ex01: ft_ultimate_ft

**Goal:** Store the value 42 in the int pointed to by a pointer to a pointer to a pointer ... (9 levels).

- **Prototype:** `void ft_ultimate_ft(int *********nbr);`
- **Allowed functions:** None.
- **How it works:**
  - Takes a pointer to a pointer to a pointer ... to an int.
  - Sets the value at that address to 42 using `*********nbr = 42;`.

**Example usage:**
```c
int x;
int *p1 = &x;
int **p2 = &p1;
// ... up to 9 levels
ft_ultimate_ft(&p8);
// x is now 42
```
