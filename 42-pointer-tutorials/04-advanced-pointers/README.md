# 04-advanced-pointers: Taking It to the Next Level

## Learning Objectives
By the end of this section, you should be able to:
- Understand and use pointer to pointer (double pointers)
- Work with arrays of pointers (like `argv`)
- Understand basic function pointers
- Navigate multi-level pointer indirection

## Key Concepts

### Pointer to Pointer (Double Pointer)

A pointer that points to another pointer:

```c
int x = 42;
int *ptr = &x;      // ptr points to x
int **pptr = &ptr;  // pptr points to ptr

**pptr  // Follows two arrows to get 42
*pptr   // Gets ptr (address of x)
pptr    // Address of ptr
```

**Memory visualization:**
```
x: [42]  <-- ptr points here
ptr: [addr of x]  <-- pptr points here
pptr: [addr of ptr]
```

### When Do You Need Double Pointers?

1. **Modify a pointer in a function:**
```c
void change_pointer(int **pp)
{
    *pp = new_address;  // Changes original pointer
}
```

2. **Arrays of strings (like argv):**
```c
int main(int argc, char **argv)  // Array of strings
```

3. **2D arrays dynamically allocated:**
```c
int **matrix;  // Pointer to array of pointers
```

## Files in This Section

### 00-pointer-to-pointer.c
Basic double pointer example:
- `x` is an int
- `ptr` points to `x`
- `pptr` points to `ptr`
- `**pptr` accesses `x`'s value

**Python Tutor Focus:**
- See the chain: `pptr` → `ptr` → `x`
- Count the arrows (two levels of indirection)
- Notice `**pptr` equals `x`

### 01-array-of-pointers.c
Shows array of pointers to strings:
- Each element is a `char *` (pointer to string)
- Just like `argv` in main!
- Different strings at different locations

**Python Tutor Focus:**
- See `strs[0]`, `strs[1]`, `strs[2]` pointing to different strings
- Understand how this relates to `char **argv`

### 02-function-pointers.c
Introduction to function pointers:
- Store function address in a variable
- Call different functions through the pointer
- Enables runtime function selection

**Python Tutor Focus:**
- Watch `operation` point to different functions
- See results change based on which function is called
- Understand function addresses

## Understanding Double Pointers

### Levels of Indirection

| Expression | Type | What It Gives You |
|------------|------|-------------------|
| `x` | `int` | Value of x |
| `&x` | `int *` | Address of x |
| `ptr` | `int *` | Address of x (same as &x) |
| `*ptr` | `int` | Value of x |
| `&ptr` | `int **` | Address of ptr |
| `pptr` | `int **` | Address of ptr |
| `*pptr` | `int *` | Value of ptr (address of x) |
| `**pptr` | `int` | Value of x |

### Common Pattern: Modifying a Pointer

**Problem:** Change where a pointer points from inside a function

```c
void change_ptr(int **pp, int *new_target)
{
    *pp = new_target;  // Changes original pointer
}

int main(void)
{
    int x = 10, y = 20;
    int *ptr = &x;
    
    change_ptr(&ptr, &y);  // Now ptr points to y
    // *ptr is now 20
}
```

## Understanding argv

### The Declaration
```c
int main(int argc, char **argv)
```
Or equivalently:
```c
int main(int argc, char *argv[])
```

### What It Means
- `argc`: number of arguments
- `argv`: array of strings (array of char pointers)

```
argv[0] → "program_name"
argv[1] → "first_arg"
argv[2] → "second_arg"
...
argv[argc - 1] → last argument
argv[argc] → NULL
```

### Accessing Arguments
```c
argv[0]      // First argument (program name)
argv[1]      // Second argument
argv[1][0]   // First character of second argument
*argv[1]     // Same as argv[1][0]
```

### Walking Through argv
```c
int i = 0;
while (i < argc)
{
    // Print each argument
    ft_putstr(argv[i]);
    ft_putchar('\n');
    i++;
}
```

Or with pointer:
```c
char **ptr = argv;
while (*ptr != NULL)
{
    ft_putstr(*ptr);
    ft_putchar('\n');
    ptr++;
}
```

## Function Pointers Basics

### Declaration
```c
return_type (*pointer_name)(parameter_types);

// Examples:
int (*func_ptr)(int, int);           // Takes 2 ints, returns int
void (*action)(char *);              // Takes string, returns nothing
char *(*getter)(void);               // Takes nothing, returns string
```

### Assignment and Use
```c
int add(int a, int b)
{
    return (a + b);
}

int main(void)
{
    int (*operation)(int, int);
    
    operation = &add;      // Point to add function
    int result = operation(3, 4);  // Calls add(3, 4)
    // result is 7
}
```

### Why Use Function Pointers?

1. **Runtime function selection:**
```c
int (*math_op)(int, int);
if (choice == '+')
    math_op = &add;
else
    math_op = &multiply;
    
result = math_op(x, y);
```

2. **Callback functions:**
```c
void process_array(int *arr, int size, int (*func)(int))
{
    int i = 0;
    while (i < size)
    {
        arr[i] = func(arr[i]);
        i++;
    }
}
```

3. **Jump tables (common in 42 projects):**
```c
int (*operations[4])(int, int) = {add, sub, mul, div};
result = operations[choice](x, y);
```

## Practice Exercises

1. **Triple Pointer**
   - Create `int ***ppptr`
   - Make it point through two pointers to an int
   - Access the int value with `***ppptr`

2. **2D Array with Pointers**
   - Create array of 3 int pointers
   - Each pointer points to an array of 4 ints
   - Access elements like `arr[i][j]`

3. **Function Pointer Array**
   - Create array of function pointers
   - Each function takes two ints
   - Create a calculator using the array

4. **String Array Manipulation**
   - Create `char **strings` with 5 strings
   - Count total characters across all strings
   - Find longest string

## Common Mistakes

❌ **Confusing levels:**
```c
int **pp;
*pp = 42;  // ERROR! *pp is a pointer, not an int
```

✅ **Correct:**
```c
int **pp;
**pp = 42;  // OK! **pp is the int
```

❌ **Uninitialized chain:**
```c
int **pp;
**pp = 42;  // CRASH! pp doesn't point anywhere
```

✅ **Correct:**
```c
int x;
int *p = &x;
int **pp = &p;
**pp = 42;  // OK!
```

❌ **Function pointer syntax:**
```c
int *func_ptr(int, int);  // This declares a function!
```

✅ **Correct:**
```c
int (*func_ptr)(int, int);  // This declares a pointer!
```

## 42 Exam Tips

### Common Tasks with Double Pointers:

**ft_ultimate_ft:**
```c
void ft_ultimate_ft(int *********nbr)
{
    *********nbr = 42;
}
```

**Working with argv:**
```c
// Count total characters in all arguments
int count_all_chars(char **argv)
{
    int total = 0;
    int i = 0;
    
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            total++;
            j++;
        }
        i++;
    }
    return (total);
}
```

### Testing with argv:
```bash
./program arg1 arg2 arg3
# argc = 4
# argv[0] = "./program"
# argv[1] = "arg1"
# argv[2] = "arg2"
# argv[3] = "arg3"
# argv[4] = NULL
```

## Visualization Tips

### Drawing Memory Diagrams

For `int **pptr`:
```
pptr → [addr1] → [addr2] → [42]
       int**     int*      int
       
To get 42:
pptr    = address of first box
*pptr   = addr2 (value in first box)
**pptr  = 42 (value in second box)
```

### Following the Arrows
1. Start with the variable name
2. Each `*` means "follow one arrow"
3. `**pp` means "follow two arrows"
4. Eventually you reach the actual value

## Next Steps
Move to **05-common-mistakes** to learn:
- NULL pointer handling
- Uninitialized pointers
- Array bounds errors
- How to avoid segmentation faults
