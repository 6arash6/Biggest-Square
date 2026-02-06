# 📚 New Exam Practice Exercises - Complete Tutorial

This document lists all the newly added exercises with detailed solutions and explanations.

## 🎯 Overview of New Exercises

All new exercises are in **Exam01** folder and are common Level 1-2 problems from real 42 exams.

## 📋 Exercise Index

| Exercise | Level | Description | Key Concepts |
|----------|-------|-------------|--------------|
| `2-aff_even` | ⭐ Easy | Print characters at even positions | Modulo, bitwise, pointers |
| `3-repeat_alpha` | ⭐⭐ Medium | Repeat each letter by alphabet position | ASCII arithmetic, loops |
| `4-fizzbuzz` | ⭐ Easy | Classic FizzBuzz problem | Modulo, conditions order |
| `5-aff_odd` | ⭐ Easy | Print characters at odd positions | Complement to aff_even |
| `6-alpha_mirror` | ⭐⭐ Medium | Mirror alphabet positions | Formula derivation |
| `7-search_and_replace` | ⭐⭐ Medium | Find and replace character | Argument validation |

---

## 🔥 Featured Exercise: aff_even (Print Even Positions)

### Location
`Exams Practice/Exam01/2-aff_even/`

### What You'll Find
- `subject.en.txt` - Official exercise description
- `solution1_index_modulo.c` - Best for beginners (uses `i % 2`)
- `solution2_bitwise.c` - **Recommended for exams** (uses `i & 1`)
- `solution3_pointer_safe.c` - Shows pointer skills (safe version)
- `solution4_pointer_risky.c` - **WARNING:** Demonstrates common mistake
- `solution5_compact.c` - Ultra-compact for speed coding
- `README.md` - Complete tutorial with all solutions explained

### Why 5 Different Solutions?
Each solution teaches different concepts:
1. **Clarity and correctness** (modulo)
2. **Efficiency and "42 style"** (bitwise)
3. **Pointer mastery** (safe pointer arithmetic)
4. **Common pitfalls** (what NOT to do)
5. **Exam speed** (compact version)

### Quick Example
```c
// Input: ./aff_even "hello"
// Output: hlo
// Explanation: Positions 0,2,4 → h,l,o
```

### Recommended Solution for Exams
```c
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    if (ac == 2)
        while (av[1][i])
            if ((i & 1) == 0)
                write(1, &av[1][i], 1), i++;
            else
                i++;
    write(1, "\n", 1);
    return (0);
}
```

---

## 🧪 Testing Your Solutions

### NEW: All Exercises Include Test Files! ✨

Every exercise now has a `test_*.c` file with comprehensive test cases:

#### Option 1: Quick Test Script (Easiest!)
```bash
# From "Exams Practice" directory
chmod +x test_all_exercises.sh
./test_all_exercises.sh
```

#### Option 2: Using Makefile
```bash
cd "Exams Practice/Exam01"
make test_all              # Run all tests
make test_aff_even         # Run specific test
make help                  # See all options
```

#### Option 3: Manual Testing
```bash
# Test individual exercise
cd "Exams Practice/Exam01/2-aff_even"
gcc -Wall -Wextra -Werror test_aff_even.c -o test
./test
rm test
```

📚 **See [Exam01/TESTING_GUIDE.md](Exam01/TESTING_GUIDE.md) for complete testing documentation**

### Test File Features

✅ **10-12 test cases per exercise**  
✅ **Color-coded output** (pass/fail indicators)  
✅ **Edge case coverage** (empty, single char, invalid args)  
✅ **Expected vs actual comparison**  
✅ **Detailed comments explaining logic**  
✅ **Ready to compile and run**

---

## 📖 Exercise Summaries

### 3-repeat_alpha
**Concept:** Repeat each letter based on its alphabetical position

```c
// Input: ./repeat_alpha "abc"
// Output: abbccc
// Explanation: a=1 time, b=2 times, c=3 times
```

**Key Formula:**
```c
repeat = letter - 'a' + 1;  // For lowercase
repeat = letter - 'A' + 1;  // For uppercase
```

**Location:** `Exams Practice/Exam01/3-repeat_alpha/`

---

### 4-fizzbuzz
**Concept:** Classic FizzBuzz - numbers 1-100 with replacements

```c
// Output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz...
```

**Critical Detail:** Check multiples of 15 BEFORE checking 3 or 5!

```c
if (i % 15 == 0)      // Must be first!
    write(1, "fizzbuzz", 8);
else if (i % 3 == 0)   // Then check 3
    write(1, "fizz", 4);
else if (i % 5 == 0)   // Then check 5
    write(1, "buzz", 4);
```

**Location:** `Exams Practice/Exam01/4-fizzbuzz/`

---

### 5-aff_odd
**Concept:** Complement to aff_even - print odd positions

```c
// Input: ./aff_odd "hello"
// Output: el
// Explanation: Positions 1,3 → e,l
```

**Simple Change from aff_even:**
```c
// aff_even uses: if (i % 2 == 0)
// aff_odd uses:  if (i % 2 == 1)
// Or bitwise:    if (i & 1)
```

**Location:** `Exams Practice/Exam01/5-aff_odd/`

---

### 6-alpha_mirror
**Concept:** Mirror each letter in the alphabet (a↔z, b↔y, etc.)

```c
// Input: ./alpha_mirror "abc"
// Output: zyx
```

**The Mirror Formula:**
```c
// For lowercase:
mirrored = 'z' - (original - 'a');

// For uppercase:
mirrored = 'Z' - (original - 'A');
```

**How it works:**
- 'a' (position 0) → 'z' - 0 = 'z'
- 'b' (position 1) → 'z' - 1 = 'y'
- 'c' (position 2) → 'z' - 2 = 'x'

**Location:** `Exams Practice/Exam01/6-alpha_mirror/`

---

### 7-search_and_replace
**Concept:** Replace all occurrences of one character with another

```c
// Input: ./search_and_replace "Papache est un sabre" "a" "o"
// Output: Popoche est un sobre
```

**Important Validations:**
```c
// Must have exactly 3 arguments AND both search/replace are single chars
if (ac == 4 && !av[2][1] && !av[3][1])
{
    // !av[2][1] checks that second char is '\0'
    // meaning it's a single character string
}
```

**Location:** `Exams Practice/Exam01/7-search_and_replace/`

---

## 🎓 Learning Path Recommendation

### If you're new to exams:
1. Start with `aff_even` - Read ALL 5 solutions
2. Do `aff_odd` - Apply what you learned
3. Try `fizzbuzz` - Practice condition ordering
4. Attempt `search_and_replace` - Learn argument validation

### If you're exam-ready:
1. Time yourself with `aff_even` (solution 2 or 5)
2. Speed-code `repeat_alpha` without looking
3. Complete `alpha_mirror` (formula practice)
4. Master all 7 exercises under time pressure

---

## 💡 Common Exam Tips from These Exercises

### 1. Bitwise vs Modulo
```c
i % 2 == 0  // Slower, but clear
(i & 1) == 0  // Faster, "42 style"

i % 2 == 1  // Check for odd
i & 1  // Same, but compact
```

### 2. Argument Validation Patterns
```c
if (ac == 2)              // Exactly one argument
if (ac == 4 && !av[2][1]) // Exactly 3 args + single char check
```

### 3. Pointer Arithmetic Safety
```c
// SAFE:
str++;
if (*str)
    str++;

// UNSAFE:
str += 2;  // Can go past '\0'!
```

### 4. ASCII Arithmetic
```c
'a' - 'a' = 0  // Position in alphabet
'c' - 'a' = 2
'z' - 'a' = 25

'5' - '0' = 5  // Convert digit char to int
```

---

## 🧪 Testing Your Solutions

### Compilation
```bash
gcc -Wall -Wextra -Werror yourfile.c -o program_name
```

### Test Cases to Always Check
1. **Normal case:** `./program "hello"`
2. **Empty string:** `./program ""`
3. **No arguments:** `./program`
4. **Too many arguments:** `./program "a" "b"`
5. **Single character:** `./program "a"`
6. **Special characters:** `./program "42!@#"`

### Using cat -e to verify newlines
```bash
./program "test" | cat -e  # Should show: result$
```

---

## 📊 Exercise Difficulty Progression

```
Level 0: Hello World, aff_z
         ↓
Level 1: aff_even, aff_odd, fizzbuzz   ← Start here
         ↓
Level 2: repeat_alpha, alpha_mirror, search_and_replace
         ↓
Level 3: rot_13, wdmatch, inter
         ↓
Level 4+: More complex string/array problems
```

---

## 🔗 Related Exercises in Repo

Compare your new exercises with existing ones:
- `Exam01/2-first_word` - Similar string iteration
- `Exam01/2-rotone` - Character shifting (compare with alpha_mirror)
- `Exam01/2-rot_13` - Another transformation (compare with alpha_mirror)
- `Exam02/1-ft_strlen` - Basic pointer practice

---

## 📚 Additional Resources

### Want More Practice?
1. Re-do each exercise with different approaches
2. Time yourself - aim for < 5 minutes per Level 1 exercise
3. Try implementing without looking at solutions
4. Explain the solution to someone else

### Deep Dive Tutorials
- Check `/42-pointer-tutorials/` for pointer mastery
- Each exercise file has extensive comments
- README files explain concepts step-by-step

---

## ✅ Checklist for Exam Readiness

Use this for each new exercise:

- [ ] Can write solution from memory
- [ ] Understand ALL solution approaches
- [ ] Can explain the algorithm verbally
- [ ] Handle all edge cases (empty, single char, no args)
- [ ] Compile with no warnings (-Wall -Wextra -Werror)
- [ ] Complete in under 10 minutes
- [ ] Can code with `vim` (not VSCode!)

---

## 🚀 Next Steps

1. **Practice each exercise** in the order listed above
2. **Read all solution files** - comments are tutorials!
3. **Compare different approaches** - understand trade-offs
4. **Time yourself** - exam conditions matter
5. **Redo from scratch** - muscle memory is key

**Good luck in your exams! 🎯**

---

*Created: February 2026*  
*Exercises based on real 42 exam questions*  
*All solutions tested and validated*
