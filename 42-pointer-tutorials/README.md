# 42 Pointer Tutorials

A comprehensive guide to learning C pointers for 42 school students, designed to work with [Python Tutor](https://pythontutor.com/c.html) for step-by-step visualization.

## 🎯 Why This Guide?

Pointers are one of the most challenging concepts in C programming, yet they're fundamental to succeeding at 42 school. This tutorial series:

- **Starts from zero** - no prior pointer knowledge needed
- **Visual learning** - works with Python Tutor for interactive visualization
- **42-focused** - follows Norminette style and exam patterns
- **Practical** - includes real 42 exercises and common exam tasks
- **Progressive** - builds from basics to advanced concepts

## 🚀 Getting Started

### What You Need
- A C compiler (gcc)
- Access to [Python Tutor](https://pythontutor.com/c.html)
- Basic C knowledge (variables, loops, functions)

### How to Use This Guide

1. **Read the section README** - Understand the concepts
2. **Copy code to Python Tutor** - Visualize execution
3. **Step through slowly** - Watch memory and pointers
4. **Modify and experiment** - Change values, add lines
5. **Do the exercises** - Practice makes perfect

### Using Python Tutor

1. Go to https://pythontutor.com/c.html
2. Copy any `.c` file from this tutorial
3. Click "Visualize Execution"
4. Use "Next >" to step through line by line
5. Watch how variables and pointers change

**Key Features:**
- Variables shown as boxes with values
- Pointers shown as arrows pointing to other boxes
- Stack frames visible for function calls
- Memory addresses displayed

**Tips:**
- Step through slowly
- Watch the arrows (pointers)
- Follow what happens to values
- Re-run as many times as needed

## 📚 Tutorial Structure

### [00-basics](00-basics/)
**What you'll learn:**
- What is a pointer
- Address operator `&`
- Dereference operator `*`
- Declaring and initializing pointers
- Changing values through pointers

**Files:**
- `00-what-is-pointer.c` - First pointer example
- `01-address-and-dereference.c` - Using & and *
- `02-pointer-assignment.c` - Modifying through pointers

**Start here if:** You're new to pointers

---

### [01-pointer-arithmetic](01-pointer-arithmetic/)
**What you'll learn:**
- Incrementing and decrementing pointers
- How pointers move through memory
- Pointer difference
- Array traversal with pointers

**Files:**
- `00-increment-decrement.c` - ptr++ and ptr--
- `01-array-traversal.c` - Walking through arrays
- `02-pointer-difference.c` - Calculating distances

**Start here if:** You understand basic pointers but not arithmetic

---

### [02-pointers-and-arrays](02-pointers-and-arrays/)
**What you'll learn:**
- Arrays as pointers
- Equivalence: `arr[i]` = `*(arr + i)`
- String manipulation
- Array vs pointer differences

**Files:**
- `00-array-as-pointer.c` - Array name is a pointer
- `01-array-vs-pointer.c` - Four ways to access elements
- `02-string-manipulation.c` - Working with strings

**Start here if:** You need to understand array/pointer relationship

---

### [03-pointers-and-functions](03-pointers-and-functions/)
**What you'll learn:**
- Pass by value vs pass by reference
- Modifying variables in functions
- Why we need `&` when calling
- Passing arrays to functions

**Files:**
- `00-pass-by-reference.c` - Changing variables
- `01-swap-function.c` - Classic swap with pointers
- `02-modify-array.c` - Modifying arrays in functions

**Start here if:** You need to modify variables in functions

---

### [04-advanced-pointers](04-advanced-pointers/)
**What you'll learn:**
- Pointer to pointer (double pointers)
- Arrays of pointers
- Understanding `argv`
- Function pointers basics

**Files:**
- `00-pointer-to-pointer.c` - `int **pptr`
- `01-array-of-pointers.c` - Like `char **argv`
- `02-function-pointers.c` - Pointers to functions

**Start here if:** You're comfortable with basics and need advanced concepts

---

### [05-common-mistakes](05-common-mistakes/)
**What you'll learn:**
- NULL pointer handling
- Uninitialized pointers (wild pointers)
- Array bounds errors
- How to avoid segmentation faults
- Debugging tips

**Files:**
- `00-null-pointer.c` - Safe NULL handling
- `01-uninitialized-pointer.c` - Proper initialization
- `02-array-bounds.c` - Staying in bounds

**Start here if:** You're getting crashes or segfaults

---

### [utils/](utils/)
**What you'll find:**
- `ft_putchar.c` - Write a character
- `ft_putstr.c` - Write a string
- `ft_putnbr.c` - Write a number
- Helper functions for 42 exercises

**Why?** During 42 exams, you can't use `printf`! These functions use only `write()`.

## 🎓 42 School Specifics

### Code Style (Norminette)

All code follows 42 Norminette:
- ✅ Functions use `(void)` for no parameters
- ✅ Variables declared at the top
- ✅ Maximum 25 lines per function
- ✅ Tab indentation
- ✅ Return format: `return (0);`
- ✅ Only `<unistd.h>` header used

### Compilation

Compile any file with:
```bash
gcc -Wall -Wextra -Werror filename.c
```

Compile with utilities:
```bash
gcc -Wall -Wextra -Werror utils/ft_putchar.c utils/ft_putnbr.c your_file.c
```

### Exam Functions

During 42 exams, you typically:

**✅ CAN use:**
- `write` - output to stdout
- `malloc` / `free` - dynamic memory
- Functions you write yourself

**❌ CANNOT use:**
- `printf` - use `write` or `ft_putstr`
- `strlen` - write `ft_strlen`
- `strcpy` - write `ft_strcpy`
- Most standard library functions

**Check allowed functions:** Always read the subject carefully!

### Using `man` During Exams

The `man` command is your friend:

```bash
# Search for string-related functions
man -k "string"

# Search for memory-related functions
man -k "memory"

# Get details about write (system call)
man 2 write

# Get details about strlen (library function)
man 3 strlen
```

**Understanding man sections:**
- Section 1: User commands
- Section 2: System calls (write, read, open)
- Section 3: Library functions (strlen, malloc)

### Common 42 Exercises Using Pointers

**Piscine C02-C03:**
- `ft_strcpy` - Copy strings with pointers
- `ft_strcmp` - Compare strings
- `ft_strlen` - Count characters

**Piscine C04-C05:**
- `ft_putnbr` - Print numbers
- `ft_atoi` - String to integer
- `ft_recursive_factorial` - Recursion

**Piscine C06:**
- Working with `argc` and `argv`
- Program arguments

**Common Exam Exercises:**
- `ft_swap` - Swap two integers
- `ft_strlen` - String length
- `ft_putstr` - Print string
- `ft_rev_int_tab` - Reverse array
- `ft_sort_int_tab` - Sort array

## 🛠️ Exam Tips

### Before the Exam
1. ✅ Practice all tutorial files
2. ✅ Understand each concept
3. ✅ Memorize utility function patterns
4. ✅ Know how to use `man`

### During the Exam
1. 🧠 **Read carefully** - What functions are allowed?
2. 🔍 **Use man** - `man 2 write`, `man 3 malloc`
3. 🎯 **Start simple** - Get basic version working first
4. 🔬 **Test edge cases** - NULL, empty strings, size 0
5. ⚡ **Check bounds** - Off-by-one errors are common

### Common Exam Mistakes
- ❌ Forgetting NULL checks
- ❌ Off-by-one in loops (`i <= size` vs `i < size`)
- ❌ Not initializing pointers
- ❌ Using forbidden functions
- ❌ Forgetting null terminator in strings

### Testing Strategy
```c
int main(void)
{
    // Test normal case
    test_normal();
    
    // Test edge cases
    test_with_null();
    test_with_empty();
    test_with_one_element();
    
    return (0);
}
```

## 📖 Learning Path

### Beginner (Week 1)
1. Complete 00-basics
2. Complete 01-pointer-arithmetic
3. Practice with Python Tutor

### Intermediate (Week 2)
1. Complete 02-pointers-and-arrays
2. Complete 03-pointers-and-functions
3. Write 5 functions from scratch

### Advanced (Week 3)
1. Complete 04-advanced-pointers
2. Study 05-common-mistakes
3. Practice exam exercises

### Master Level
1. Can write any string function
2. Understand argv completely
3. Debug segfaults quickly
4. Pass 42 exams confidently

## 🐛 Debugging

### When You Get a Segfault

1. **Check NULL pointers:**
```c
if (ptr == NULL)
    return ;
```

2. **Check initialization:**
```c
int *ptr = &variable;  // Not: int *ptr;
```

3. **Check array bounds:**
```c
while (i < size)  // Not: i <= size
```

4. **Use GDB:**
```bash
gcc -g program.c
gdb ./a.out
run
backtrace
```

### Common Fixes

**Problem:** Segfault on string functions
```c
// Add NULL check
if (str == NULL)
    return (0);
```

**Problem:** Array out of bounds
```c
// Check loop condition
while (i < size)  // Not <=
```

**Problem:** Uninitialized pointer
```c
int *ptr = NULL;  // Start with NULL
// Later...
ptr = &variable;  // Then assign
```

## 🎯 Practice Exercises

### Easy
1. Write `ft_strlen` using pointers
2. Write `ft_putstr` 
3. Write `ft_strcpy`

### Medium
1. Write `ft_swap` for two ints
2. Write `ft_rev_int_tab` (reverse array)
3. Write `ft_strcmp`

### Hard
1. Write `ft_split` (split string by delimiter)
2. Write `ft_atoi` (string to int)
3. Work with `argv` to process arguments

## 📝 Quick Reference

### Pointer Basics
```c
int x = 42;
int *ptr = &x;   // ptr points to x
*ptr = 99;       // Changes x to 99
```

### Array/Pointer Equivalence
```c
arr[i]    ==  *(arr + i)
&arr[i]   ==  arr + i
```

### Function Parameters
```c
void func(int *ptr);     // Pass by reference
void func(int arr[]);    // Array (is pointer)
void func(char **strs);  // Array of strings
```

### Common Patterns
```c
// String length
while (*str++)
    len++;

// Array traversal
while (i < size)
    sum += arr[i++];

// NULL check
if (ptr == NULL)
    return ;
```

## 🔗 Additional Resources

- **Python Tutor:** https://pythontutor.com/c.html
- **42 Intra:** Check norms and subjects
- **Man pages:** `man write`, `man 3 strlen`
- **GDB tutorial:** `man gdb`

## 💡 Final Tips

1. **Visualize everything** - Use Python Tutor religiously
2. **Practice daily** - 30 minutes beats 3 hours once
3. **Understand, don't memorize** - Know WHY, not just HOW
4. **Debug systematically** - Check NULL, bounds, initialization
5. **Help others** - Teaching reinforces learning

## 🎓 Success Metrics

You're ready when you can:
- ✅ Explain pointers to another student
- ✅ Write `ft_strlen` without reference
- ✅ Debug a segfault in under 5 minutes
- ✅ Understand any pointer-based function
- ✅ Pass 42 exams with confidence

## 🙏 Contributing

Found a typo? Have a suggestion? Want to add an exercise?
Feel free to contribute! This is a learning resource for the entire 42 community.

## 📜 License

Free to use for 42 students and anyone learning C programming.

---

**Remember:** Pointers are not magic. They're just variables that store addresses. With practice and visualization, they'll become second nature.

**Good luck at 42! 🚀**
