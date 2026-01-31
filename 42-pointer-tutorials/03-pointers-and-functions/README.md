# 03-pointers-and-functions: Modifying Data Through Functions

## Learning Objectives
By the end of this section, you should be able to:
- Understand pass by value vs pass by reference
- Modify variables through function parameters
- Pass arrays to functions correctly
- Write functions that modify multiple values

## Key Concepts

### Pass by Value (Default)
When you pass a variable normally, the function gets a COPY:

```c
void add_ten(int x)
{
    x = x + 10;  // Changes the COPY, not original
}

int main(void)
{
    int num = 5;
    add_ten(num);
    // num is still 5! Function changed the copy
}
```

### Pass by Reference (Using Pointers)
When you pass a pointer, the function can modify the original:

```c
void add_ten(int *x)
{
    *x = *x + 10;  // Changes the ORIGINAL
}

int main(void)
{
    int num = 5;
    add_ten(&num);  // Pass address
    // num is now 15! Function changed original
}
```

### Why This Matters
- Return value can only return ONE thing
- With pointers, you can modify MULTIPLE variables
- Essential for functions like `swap`, `split`, etc.

## Files in This Section

### 00-pass-by-reference.c
Simplest example of modifying a variable:
- Function takes `int *num` (pointer to int)
- Modifies value using `*num`
- Original variable changes

**Python Tutor Focus:**
- Watch `x` change from inside the function
- See the connection between `x` and `num`

### 01-swap-function.c
Classic interview question: swap two values
- Cannot do this with pass by value
- MUST use pointers
- Shows the three-step swap algorithm

**Python Tutor Focus:**
- See `temp` hold the first value
- Watch values swap step by step
- Verify `a` and `b` are swapped after function

### 02-modify-array.c
Demonstrates array parameter behavior:
- Arrays are ALWAYS passed as pointers
- Changes inside function affect original
- Common pattern in 42 exercises

**Python Tutor Focus:**
- Watch each array element double
- Notice changes persist after function returns

## Understanding Function Parameters

### For Single Values

**Pass by Value:**
```c
void func(int x)
{
    x = 100;  // Changes copy only
}
```

**Pass by Reference:**
```c
void func(int *x)
{
    *x = 100;  // Changes original
}

// Call with:
func(&variable);
```

### For Arrays

Arrays are ALWAYS passed by reference (as pointers):

```c
void modify(int arr[])    // Same as: int *arr
{
    arr[0] = 99;  // Changes original array!
}

// Call with:
modify(my_array);  // Don't need &
```

Why? Because array name is already a pointer!

## Common Function Patterns

### Pattern 1: Modify Single Value
```c
void increment(int *n)
{
    (*n)++;
}

// Use:
int x = 5;
increment(&x);  // x becomes 6
```

### Pattern 2: Swap Two Values
```c
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Use:
int x = 1, y = 2;
swap(&x, &y);  // x=2, y=1
```

### Pattern 3: Modify Array
```c
void fill_array(int *arr, int size, int value)
{
    int i = 0;
    while (i < size)
    {
        arr[i] = value;
        i++;
    }
}

// Use:
int nums[5];
fill_array(nums, 5, 42);
```

### Pattern 4: Return Multiple Values
```c
void divide(int a, int b, int *quotient, int *remainder)
{
    *quotient = a / b;
    *remainder = a % b;
}

// Use:
int q, r;
divide(10, 3, &q, &r);  // q=3, r=1
```

## Practice Exercises

1. **ft_ultimate_ft**
   - Take a pointer to pointer to pointer... to int (9 levels)
   - Set the final value to 42
   - Classic 42 piscine exercise

2. **ft_div_mod**
   - Take two ints and two pointers
   - Calculate division and modulo
   - Store results in the pointers

3. **ft_sort_int_tab**
   - Take an array and its size
   - Sort the array in place
   - Use swap helper function

4. **ft_rev_int_tab**
   - Take an array and its size
   - Reverse the array in place
   - Use two pointers (start and end)

## Common Mistakes

❌ **Forgetting the &:**
```c
void func(int *x);

int num = 5;
func(num);  // ERROR! Passing value, not address
```

✅ **Correct:**
```c
func(&num);  // OK! Passing address
```

❌ **Dereferencing incorrectly:**
```c
void func(int *x)
{
    x = 100;  // Changes pointer, not value!
}
```

✅ **Correct:**
```c
void func(int *x)
{
    *x = 100;  // Changes value at address
}
```

❌ **Returning local array:**
```c
int *create_array(void)
{
    int arr[5];
    return arr;  // DANGER! arr is destroyed after return
}
```

✅ **Correct (with malloc):**
```c
int *create_array(void)
{
    int *arr = malloc(5 * sizeof(int));
    return arr;  // OK! malloc'd memory persists
}
```

## Exam Tips for 42

### When to Use Pointers in Functions:
1. Need to modify parameter (like swap)
2. Need to return multiple values (like div_mod)
3. Passing array (automatic, but be aware)
4. Working with strings (they're arrays)

### Common Function Signatures:
```c
void ft_swap(int *a, int *b);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_sort_int_tab(int *tab, int size);
int ft_strlen(char *str);
char *ft_strcpy(char *dest, char *src);
```

### Testing Your Functions:
```c
int main(void)
{
    // Test with simple values
    int a = 1, b = 2;
    ft_swap(&a, &b);
    // Verify: a should be 2, b should be 1
    
    // Test with arrays
    int arr[] = {3, 1, 4, 1, 5};
    ft_sort_int_tab(arr, 5);
    // Verify: arr should be {1, 1, 3, 4, 5}
    
    return (0);
}
```

## Memory Diagram

When you call: `func(&x)`

```
main():                 func(int *ptr):
┌─────────┐            ┌─────────┐
│ x: 42   │<───────────│ ptr     │
│ (0x100) │   points   │ (0x100) │
└─────────┘    to      └─────────┘
```

- `x` lives in main's stack frame
- `ptr` lives in func's stack frame
- `ptr` contains address `0x100` (where `x` lives)
- `*ptr` accesses the value at `0x100` (which is `x`)

## Next Steps
Move to **04-advanced-pointers** to explore:
- Pointer to pointer (double pointers)
- Arrays of pointers
- Function pointers
