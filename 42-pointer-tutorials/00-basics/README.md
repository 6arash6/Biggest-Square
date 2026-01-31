# 00-basics: Introduction to Pointers

## Learning Objectives
By the end of this section, you should be able to:
- Understand what a pointer is
- Declare and initialize pointers
- Use the address-of operator `&`
- Use the dereference operator `*`
- Modify variables through pointers

## Key Concepts

### What is a Pointer?
A **pointer** is a variable that stores a memory address. Instead of holding a value like `42`, a pointer holds the location in memory where that value is stored.

Think of it like this:
- Regular variable: A box with a value inside
- Pointer: An arrow pointing to a box

### The Two Important Operators

#### 1. Address-of Operator: `&`
Gets the memory address of a variable.
```c
int x = 42;
int *ptr = &x;  // ptr now holds the address of x
```

#### 2. Dereference Operator: `*`
Accesses the value at the address stored in a pointer.
```c
int value = *ptr;  // value now contains 42
```

### Pointer Declaration
```c
int *ptr;     // ptr is a pointer to an int
char *str;    // str is a pointer to a char
```

## Files in This Section

### 00-what-is-pointer.c
The simplest possible pointer example. Shows:
- Declaring a variable
- Declaring a pointer
- Assigning an address to a pointer

**Copy to Python Tutor:** https://pythontutor.com/c.html

### 01-address-and-dereference.c
Demonstrates both operators in action:
- Using `&` to get an address
- Using `*` to read the value at that address

**Focus on:** How `*ptr` gives you the value stored in `num`

### 02-pointer-assignment.c
Shows the power of pointers:
- Modifying a variable through a pointer
- How `*ptr = new_value` changes the original variable

**Focus on:** Watch how `x` changes when we do `*ptr = 99`

## Using with Python Tutor

1. Go to https://pythontutor.com/c.html
2. Copy the code from any `.c` file
3. Click "Visualize Execution"
4. Use "Next >" button to step through line by line
5. Watch the variables and arrows in the visualization

### What to Watch For:
- **Variables** appear as boxes with values
- **Pointers** appear as boxes with arrows pointing to other boxes
- When you **dereference** (`*ptr`), follow the arrow to see the value

## Practice Exercises

1. **Basic Pointer**
   - Create a variable `age` with value 25
   - Create a pointer to it
   - Print the value using the pointer

2. **Modify Through Pointer**
   - Create a variable `score` with value 100
   - Use a pointer to change it to 95
   - Verify the original variable changed

3. **Multiple Pointers**
   - Create one variable `x`
   - Create two pointers `ptr1` and `ptr2` both pointing to `x`
   - Change `x` through `ptr1`
   - Observe that reading through `ptr2` gives the new value

## Common Mistakes to Avoid

❌ **Uninitialized pointer:**
```c
int *ptr;
*ptr = 42;  // CRASH! ptr doesn't point anywhere
```

✅ **Correct:**
```c
int x;
int *ptr = &x;
*ptr = 42;  // OK! ptr points to x
```

❌ **Forgetting the &:**
```c
int x = 42;
int *ptr = x;  // ERROR! x is not an address
```

✅ **Correct:**
```c
int x = 42;
int *ptr = &x;  // OK! &x is the address of x
```

## Next Steps
Once you're comfortable with these basics, move on to:
- **01-pointer-arithmetic**: How to move pointers around in memory
- **02-pointers-and-arrays**: The relationship between arrays and pointers
