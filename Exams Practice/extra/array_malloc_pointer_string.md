# C Exam Essentials: Arrays, malloc, Pointers, Strings

## Why This Tutorial?
Many exam exercises are built from a few core C concepts. Mastering these will help you solve most problems, even if the topic looks new!

---

## 1. Arrays
- **Definition:** Fixed-size, contiguous memory for elements of the same type.
- **Syntax:** `int arr[10];` or `char str[100];`
- **Access:** `arr[0]`, `arr[i]`
- **Common Pitfalls:** Out-of-bounds access, forgetting null-terminator for strings.

### Example: Reverse an array
```c
void reverse(int *arr, int size) {
    int i = 0, tmp;
    while (i < size / 2) {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
        i++;
    }
}
```

---

## 2. malloc (Dynamic Memory)
- **Purpose:** Allocate memory at runtime (size known only at execution).
    - Use `malloc` when you don't know the array size at compile time, or when you need to allocate memory for data structures (arrays, strings, structs) whose size depends on user input or calculations.
    - Example: Reading a file of unknown length, or creating an array based on user input.
- **Syntax:** `int *arr = malloc(n * sizeof(int));`
    - `malloc` returns a pointer to a block of memory large enough to hold `n` integers. Always cast to the correct type in C++ (not needed in C).
    - `sizeof(int)` ensures the allocation is correct for the platform (int may be 2, 4, or 8 bytes).
- **Free:** Always `free(arr);` when done.
    - If you forget to call `free`, your program will leak memory (memory is not returned to the OS), which can cause problems in long-running programs or repeated allocations.
    - Only call `free` on pointers returned by `malloc` (or related functions like `calloc`, `realloc`).
- **Check:** Always check for `NULL` after malloc.
    - If the system cannot allocate the requested memory (e.g., not enough RAM), `malloc` returns `NULL`.
    - Always check: `if (!arr) { /* handle error */ }`
    - Using a NULL pointer (e.g., `*arr = 5;`) will crash your program (segmentation fault).

### Example: Create array from 1 to n
```c
int *make_array(int n) {
    int *arr = malloc(n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    return arr;
}
```

---

## 3. Pointers
- **Definition:** Variable holding a memory address.
- **Syntax:** `int *p = &x;`
- **Dereference:** `*p` gets/sets value at address.
- **Pointer arithmetic:** `p++` moves to next element (for arrays).

### Example: Swap two integers
```c
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

---

## 4. Strings
- **Definition:** Array of chars ending with `\0`.
- **Syntax:** `char str[] = "hello";`
- **Common functions:** `ft_strlen`, `ft_strcpy`, `ft_strcmp`, etc.

### Example: String length
```c
int ft_strlen(char *str) {
    int i = 0;
    while (str[i]) i++;
    return i;
}
```

---

## 5. Combining Concepts
Many exam exercises combine these basics:
- **Dynamic string copy:** Use malloc + pointer + string
- **Array manipulation:** Use pointer arithmetic
- **Parsing:** Use arrays and pointers to walk through strings

---

## 6. Checklist for Any Exercise
- Do I need a fixed or dynamic array?
- Do I need to allocate/free memory?
- Am I using pointers correctly (no wild pointers)?
- Am I handling strings with `\0`?
- Am I checking for edge cases (empty, NULL, out-of-bounds)?

---

## 7. Practice Topics (from exam exercises)
- Reverse array/string (ft_rev_int_tab, ft_strrev)
- Copy/compare strings (ft_strcpy, ft_strcmp)
- Find substring (ft_strstr, hidenp)
- Allocate arrays (ft_range, ft_rrange)
- Parse/modify strings (epur_str, expand_str, rostring, rev_wstr)
- Sort arrays/lists (sort_int_tab, sort_list)
- Use pointer arithmetic (repeat_alpha, alpha_mirror)

---

**Master these, and you'll be ready for almost any C exam exercise!**
