# 05-common-mistakes: Learning from Errors

## Learning Objectives
By the end of this section, you should be able to:
- Recognize and avoid NULL pointer dereference
- Understand wild/uninitialized pointers
- Prevent array bounds errors
- Debug segmentation faults
- Write safer pointer code

## Key Concepts

### The Three Most Common Pointer Mistakes

1. **NULL Pointer Dereference**
   - Using a pointer that points to nothing
   - Immediate crash (segmentation fault)

2. **Uninitialized Pointer (Wild Pointer)**
   - Using a pointer before giving it a value
   - Unpredictable behavior, usually crashes

3. **Array Bounds Violation**
   - Accessing outside array boundaries
   - Corrupts memory, unpredictable results

## Files in This Section

### 00-null-pointer.c
Shows safe NULL handling:
- Check pointer before use
- `if (ptr != 0)` prevents crash
- Common with functions that can fail

**Python Tutor Focus:**
- See `ptr` is NULL (0)
- Notice the check prevents dereference
- Understand defensive programming

### 01-uninitialized-pointer.c
Demonstrates the correct approach:
- Initialize before use
- Shows what NOT to do (commented)
- Importance of initialization

**Python Tutor Focus:**
- See `good_ptr` initialized properly
- Understand why initialization matters
- Compare to what would happen without it

### 02-array-bounds.c
Shows correct array access:
- Loop bounds are correct
- Stays within array size
- Common loop pattern

**Python Tutor Focus:**
- Watch loop counter: `i < 5` not `i <= 5`
- See all valid indices accessed (0-4)
- Notice loop stops before going out of bounds

## Understanding Segmentation Faults

### What is a Segfault?
When your program tries to access memory it shouldn't:
- Dereferencing NULL
- Using uninitialized pointer
- Going outside array bounds
- Accessing freed memory
- Stack overflow

### Why Does It Crash?
Operating system protects memory:
```
Your program tries: *ptr where ptr = 0x0
OS says: "You don't own address 0! SEGFAULT!"
Program: *dies*
```

## Mistake #1: NULL Pointer

### The Problem
```c
int *ptr = NULL;  // Or 0, or not initialized to valid address
*ptr = 42;        // CRASH! NULL pointer dereference
```

### The Solution
```c
int *ptr = NULL;

if (ptr != NULL)  // Always check first!
{
    *ptr = 42;    // Safe, won't execute if NULL
}
```

### Common Sources of NULL
```c
// malloc can fail
int *arr = malloc(100 * sizeof(int));
if (arr == NULL)  // ALWAYS check malloc!
    return (ERROR);

// Functions can return NULL
char *str = ft_strdup("test");
if (str == NULL)
    return (ERROR);

// Explicitly set to NULL
int *ptr = NULL;  // Means "not pointing anywhere yet"
```

### Defensive Pattern
```c
void safe_function(int *ptr)
{
    if (ptr == NULL)
        return ;  // Or handle error
    
    *ptr = 42;  // Safe to use now
}
```

## Mistake #2: Uninitialized Pointer

### The Problem
```c
int *ptr;      // Contains garbage!
*ptr = 42;     // CRASH! or corrupts random memory
```

This is called a **wild pointer** - it points to random memory.

### The Solution
```c
int x;
int *ptr = &x;  // Initialize immediately
*ptr = 42;      // Safe!
```

Or:
```c
int *ptr = NULL;  // Start with NULL
// Later, when you have an address:
ptr = &some_variable;
*ptr = 42;  // Now safe
```

### Common Pattern
```c
int *ptr;  // Declared

// ... some code ...

ptr = malloc(sizeof(int));  // NOW initialized
if (ptr != NULL)
    *ptr = 42;
```

### Rule of Thumb
**NEVER** use a pointer before:
- Assigning it an address with `&`
- Getting address from `malloc`
- Assigning it another valid pointer
- Setting it to NULL (and checking before use)

## Mistake #3: Array Bounds

### The Problem
```c
int arr[5];  // Valid indices: 0, 1, 2, 3, 4

arr[5] = 100;   // OUT OF BOUNDS! arr[5] doesn't exist
arr[10] = 200;  // WAY out of bounds
```

### Why It's Dangerous
- No automatic bounds checking in C
- Might seem to work (writes to nearby memory)
- Corrupts other variables
- Unpredictable crashes

### The Solution
```c
int arr[5];
int i = 0;

while (i < 5)  // NOT i <= 5 !
{
    arr[i] = i * 10;
    i++;
}
```

### Off-by-One Errors
Most common mistake:
```c
int arr[5];

// WRONG!
for (int i = 0; i <= 5; i++)  // Goes to 5, which is out of bounds!
    arr[i] = 0;

// CORRECT!
for (int i = 0; i < 5; i++)   // Goes to 4, last valid index
    arr[i] = 0;
```

### With Pointers
```c
int arr[5];
int *ptr = arr;
int *end = arr + 5;  // One past last element

while (ptr < end)    // NOT ptr <= end !
{
    *ptr = 0;
    ptr++;
}
```

## More Common Mistakes

### 4. Dangling Pointer
```c
int *ptr;
{
    int x = 42;
    ptr = &x;
}  // x is destroyed here!
*ptr = 10;  // DANGER! x doesn't exist anymore
```

### 5. Memory Leak
```c
int *ptr = malloc(100 * sizeof(int));
ptr = NULL;  // Lost the address! Memory leaked
// Should have called free(ptr) first
```

### 6. Double Free
```c
int *ptr = malloc(sizeof(int));
free(ptr);
free(ptr);  // CRASH! Already freed
```

### 7. Use After Free
```c
int *ptr = malloc(sizeof(int));
*ptr = 42;
free(ptr);
*ptr = 10;  // DANGER! Memory is freed
```

## Debugging Tips

### Using GDB
```bash
gcc -g program.c -o program  # Compile with debug info
gdb ./program

# In GDB:
run                  # Run program
backtrace           # See where it crashed
print ptr           # Check pointer value
print *ptr          # See what it points to
```

### Useful GDB Commands
- `break main` - stop at main
- `next` - execute next line
- `step` - step into function
- `print variable` - show value
- `info locals` - show all local variables

### Common Patterns to Check

**NULL check:**
```c
if (ptr == NULL)
    return ;
```

**Bounds check:**
```c
if (index < 0 || index >= size)
    return ;
```

**Initialization:**
```c
int *ptr = NULL;  // Or &variable
```

## Prevention Checklist

Before using a pointer, ask:
- [ ] Is it initialized?
- [ ] Is it NULL?
- [ ] Does it point to valid memory?
- [ ] Am I within array bounds?
- [ ] Has the memory been freed?

## Practice Exercises

1. **Debugging Exercise**
   - Find and fix NULL dereferences in provided code
   - Add proper NULL checks
   - Test with invalid inputs

2. **Bounds Checker**
   - Write functions with bounds checking
   - Test with edge cases (empty array, single element)
   - Verify no out-of-bounds access

3. **Safe String Copy**
   - Implement strcpy with bounds checking
   - Handle NULL pointers safely
   - Ensure null terminator is added

4. **Memory Safety**
   - Write program using malloc
   - Add NULL checks after malloc
   - Properly free all allocated memory

## Testing Your Code

### Good Test Cases
```c
// Test NULL
ft_strlen(NULL);  // Should handle gracefully

// Test empty
ft_strlen("");    // Should return 0

// Test boundaries
char str[5] = "test";
str[0];  // OK
str[4];  // OK (null terminator)
str[5];  // OUT OF BOUNDS!

// Test edge cases
int arr[1];  // Single element
arr[0] = 42;  // OK
arr[1] = 42;  // OUT OF BOUNDS!
```

## 42 Exam Tips

### Common Mistakes in Exams

1. **Forgetting NULL checks:**
```c
// WRONG
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])  // CRASH if str is NULL!
        i++;
    return (i);
}

// CORRECT
int ft_strlen(char *str)
{
    int i;
    
    if (str == NULL)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}
```

2. **Off-by-one in loops:**
```c
// WRONG
while (i <= size)  // Goes one too far!

// CORRECT
while (i < size)   // Stops at size-1
```

3. **Not initializing:**
```c
// WRONG
int *ptr;
*ptr = 42;

// CORRECT
int x;
int *ptr = &x;
*ptr = 42;
```

### Testing in Exams
1. Test with NULL inputs
2. Test with empty strings/arrays
3. Test with single element
4. Test with maximum size
5. Check boundaries carefully

## Summary

### Golden Rules
1. **Always initialize pointers**
2. **Check for NULL before use**
3. **Stay within array bounds**
4. **Know your array size**
5. **Be careful with malloc/free**

### Remember
Most pointer bugs can be prevented by:
- Defensive programming (check inputs)
- Careful loop conditions
- Proper initialization
- Testing edge cases

## Next Steps
You've completed the pointer tutorials! Next:
- Review all sections
- Practice with 42 exercises
- Study the util functions
- Try complex examples
- Remember to use Python Tutor for visualization!
