# aff_even - Print Characters at Even Positions

## 📋 Exercise Description

Write a program that displays only the characters at **even positions** (0, 2, 4, 6...) from a string argument.

**Level:** 1 (Easy - Common in early 42 exams)

## 🎯 Requirements

- If argc != 2, print only a newline
- Position indexing starts at 0
- Only use `write()` function
- No `printf`, no headers except `<unistd.h>`

## 📊 Test Cases

| Command | Output | Explanation |
|---------|--------|-------------|
| `./aff_even "hello"` | `hlo` | Positions 0,2,4 → h,l,o |
| `./aff_even "hi"` | `h` | Position 0 → h |
| `./aff_even "a"` | `a` | Position 0 → a |
| `./aff_even "abcd"` | `ac` | Positions 0,2 → a,c |
| `./aff_even ""` | `` | Empty string → just newline |
| `./aff_even` | `` | No args → just newline |
| `./aff_even "a" "b"` | `` | Too many args → just newline |

## 🔧 Available Solutions

### Solution 1: Index with Modulo ⭐ (Recommended for beginners)
**File:** `solution1_index_modulo.c`

```c
if (i % 2 == 0)
    write(1, &argv[1][i], 1);
```

**Pros:**
- ✅ Most straightforward and readable
- ✅ Easy to understand logic
- ✅ Safe and reliable

**Cons:**
- ❌ Modulo operation is slightly slower
- ❌ Less "42 style"

**When to use:** First exam, learning, when clarity matters

---

### Solution 2: Bitwise Check ⭐⭐ (Recommended for exams)
**File:** `solution2_bitwise.c`

```c
if ((i & 1) == 0)
    write(1, &av[1][i], 1);
```

**Pros:**
- ✅ Faster than modulo (bitwise operation)
- ✅ Classic "42 style" - shows understanding
- ✅ Safe and reliable

**Cons:**
- ❌ Slightly less obvious for beginners

**When to use:** Exams, once you understand binary

**How it works:**
- `i & 1` checks the last bit of the number
- Even numbers end in 0 bit → `& 1` gives 0
- Odd numbers end in 1 bit → `& 1` gives 1

---

### Solution 3: Pointer Arithmetic (Safe) ⭐⭐⭐ (Best for pointer practice)
**File:** `solution3_pointer_safe.c`

```c
while (*str)
{
    write(1, str, 1);
    str++;
    if (*str)
        str++;
}
```

**Pros:**
- ✅ Uses pointers - shows advanced understanding
- ✅ Handles all edge cases correctly
- ✅ No array indexing

**Cons:**
- ❌ Slightly more code than index version
- ❌ Need to remember the safety check

**When to use:** When you want to show pointer skills, practicing for pointer-heavy exercises

**Critical detail:** The `if (*str)` check prevents going past `\0`!

---

### Solution 4: Pointer += 2 ⚠️ (RISKY - Not recommended)
**File:** `solution4_pointer_risky.c`

```c
while (*str)
{
    write(1, str, 1);
    str += 2;  // Dangerous!
}
```

**Pros:**
- ✅ Looks elegant and simple

**Cons:**
- ❌ **UNDEFINED BEHAVIOR** with odd-length strings
- ❌ Goes past `\0` boundary
- ❌ Might work, might crash

**When to use:** **DON'T USE THIS** unless you add safety checks

---

### Solution 5: Super Compact ⭐⭐ (Speed coding)
**File:** `solution5_compact.c`

```c
int i = -1;
if (ac == 2)
    while (av[1][++i])
        if (!(i & 1))
            write(1, av[1] + i, 1);
```

**Pros:**
- ✅ Extremely compact - fast to type
- ✅ Shows advanced techniques
- ✅ Safe and correct

**Cons:**
- ❌ Less readable
- ❌ Harder to debug

**When to use:** Time-pressured exams, when confident

---

## 🏆 Recommendation Summary

| Your Goal | Use This Solution |
|-----------|------------------|
| **Learning/First time** | Solution 1 (modulo) |
| **42 Exams** | Solution 2 (bitwise) or Solution 5 (compact) |
| **Pointer practice** | Solution 3 (pointer safe) |
| **Speed coding** | Solution 5 (compact) |
| **Readability** | Solution 1 (modulo) |

## 💡 Common Mistakes to Avoid

1. **Forgetting the final newline**
   ```c
   // Wrong:
   if (ac == 2)
   {
       // ... print chars
   }
   // Right:
   if (ac == 2)
   {
       // ... print chars
   }
   write(1, "\n", 1);  // Always print newline!
   ```

2. **Wrong argc check**
   ```c
   // Wrong:
   if (argc > 1)  // Would accept too many args
   
   // Right:
   if (argc == 2)  // Exactly one argument
   ```

3. **Using printf**
   ```c
   // Wrong:
   printf("%c", str[i]);  // Not allowed!
   
   // Right:
   write(1, &str[i], 1);
   ```

4. **Pointer going past end** (see solution 4 warnings)

## 🧪 How to Test

```bash
# Compile
gcc -Wall -Wextra -Werror solution1_index_modulo.c -o aff_even

# Test cases
./aff_even "hello"           # Expected: hlo
./aff_even "hi"              # Expected: h
./aff_even "a"               # Expected: a
./aff_even "abcd"            # Expected: ac
./aff_even ""                # Expected: (empty)
./aff_even                   # Expected: (empty)
./aff_even "42 is cool"      # Expected: 4 s cl
./aff_even "test" "extra"    # Expected: (empty)

# With cat -e to see newlines
./aff_even "hello" | cat -e  # Expected: hlo$
```

## 📚 Related Exercises

- `aff_odd` - Same but print odd positions
- `rot_13` - Character shifting
- `first_word` - String parsing
- `rev_print` - Reverse iteration

## 🎓 Concepts Practiced

- String iteration
- argc/argv handling
- Modulo operator
- Bitwise operations
- Pointer arithmetic
- write() system call
- Edge case handling

---

**Good luck in your exam! 🚀**
