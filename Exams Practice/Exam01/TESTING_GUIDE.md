# 🧪 Testing Guide for New Exam Exercises

All new exercises now include comprehensive test files with main functions!

## 📋 Quick Start

### Compile and Run Any Test

```bash
# Navigate to exercise folder
cd "Exams Practice/Exam01/2-aff_even"

# Compile the test file
gcc -Wall -Wextra -Werror test_aff_even.c -o test

# Run tests
./test

# Clean up
rm test
```

## 🎯 Test Files Overview

| Exercise | Test File | Features |
|----------|-----------|----------|
| **aff_even** | `test_aff_even.c` | 10 test cases, color output, edge cases |
| **repeat_alpha** | `test_repeat_alpha.c` | Expected vs actual, alphabet reference |
| **fizzbuzz** | `test_fizzbuzz.c` | First 20 numbers, key multiples check |
| **aff_odd** | `test_aff_odd.c` | 10 test cases, position verification |
| **alpha_mirror** | `test_alpha_mirror.c` | Mirror table, full alphabet test |
| **search_and_replace** | `test_search_and_replace.c` | 12 test cases, edge case validation |

## 🔨 How to Use Test Files

### Option 1: Test the Provided Solution
```bash
# The test file includes the solution already
gcc -Wall -Wextra -Werror test_aff_even.c -o test
./test
```

### Option 2: Test Your Own Solution

#### Method A: Copy function to test file
```bash
# Edit the test file and replace the solution function with yours
vim test_aff_even.c

# Find the solution function and replace it
# Then compile and run
gcc -Wall -Wextra -Werror test_aff_even.c -o test
./test
```

#### Method B: Create separate files
```bash
# Your solution: my_solution.c
# Test's main: test_file.c

# Remove the solution from test file, keep only main()
# Compile together:
gcc -Wall -Wextra -Werror my_solution.c test_file.c -o test
./test
```

## 📊 Understanding Test Output

### Color Coding
- 🔵 **Blue** - Test case description
- 🟢 **Green** - Success marker (✓)
- 🔴 **Red** - (Used for errors if any)

### Example Output (aff_even)

```
========================================
     AFF_EVEN - Test Suite             
========================================

Testing: "hello"
Expected: "hlo"
Got:      "hlo" ✓
---
Testing: "hi"
Expected: "h"
Got:      "h" ✓
---
[... more tests ...]

All tests completed! ✓
Manually verify the 'Got' output matches 'Expected'
```

## 🧪 Test Coverage

### aff_even - 10 Test Cases
1. ✓ Normal odd-length string
2. ✓ Normal even-length string
3. ✓ Single character
4. ✓ Four characters
5. ✓ Empty string
6. ✓ Long string (10 chars)
7. ✓ String with spaces
8. ✓ Special characters
9. ✓ Only spaces
10. ✓ Mixed case letters

### repeat_alpha - 10 Test Cases
1. ✓ Simple "abc"
2. ✓ Subject example "Alex."
3. ✓ Subject example with space
4. ✓ First letter 'a'
5. ✓ Last letter 'z'
6. ✓ Uppercase 'A'
7. ✓ Uppercase 'Z'
8. ✓ Mixed case
9. ✓ No letters (numbers/symbols)
10. ✓ Empty string

### fizzbuzz - Comprehensive
- First 20 numbers comparison
- Key multiples (15, 30, 45, 60, 75, 90)
- Full 1-100 output

### aff_odd - 10 Test Cases
1. ✓ Odd-length string
2. ✓ Even-length string
3. ✓ Single char (no odd positions)
4. ✓ Four characters
5. ✓ Empty string
6. ✓ Digits 0-9
7. ✓ String with spaces
8. ✓ Two characters
9. ✓ Special characters
10. ✓ Full position verification

### alpha_mirror - 10 Test Cases
1. ✓ Simple "abc" → "zyx"
2. ✓ Subject example
3. ✓ All lowercase
4. ✓ All uppercase
5. ✓ First and last letters (a/z, A/Z)
6. ✓ Middle letters (m/n, M/N)
7. ✓ Numbers and symbols (unchanged)
8. ✓ Mixed content
9. ✓ Empty string
10. ✓ Full alphabet

### search_and_replace - 12 Test Cases
1. ✓ Basic replacement
2. ✓ Char not in string
3. ✓ Multiple occurrences
4. ✓ Subject example
5. ✓ Replace spaces
6. ✓ Replace digits
7. ✓ Empty string
8. ✓ Single character
9. ✗ Multi-char search (invalid - should fail)
10. ✗ Too many arguments (invalid - should fail)
11. ✗ No arguments (invalid - should fail)
12. ✗ Only one argument (invalid - should fail)

## 🎓 Testing Best Practices

### During Practice
1. **First run**: Test the provided solution to see expected behavior
2. **Write your own**: Code the solution from scratch
3. **Test yours**: Replace the function in test file
4. **Compare**: If different output, debug step by step
5. **Edge cases**: Make sure ALL test cases pass

### During Exam Simulation
1. **Time yourself**: Aim to solve + test in < 10 minutes
2. **Compile first**: `gcc -Wall -Wextra -Werror` with NO warnings
3. **Quick test**: At minimum, test 3 cases:
   - Normal case
   - Empty string
   - Edge case (single char, no args, etc.)
4. **Manual testing**: If you can't use test files in exam, know how to test manually

## 🔍 Manual Testing (Exam-Style)

If you're in a real exam environment without test files:

```bash
# Compile your solution
gcc -Wall -Wextra -Werror aff_even.c -o aff_even

# Test manually
./aff_even "hello"           # Should: hlo
./aff_even "hi"              # Should: h
./aff_even ""                # Should: (empty)
./aff_even                   # Should: (empty)
./aff_even "test" "extra"    # Should: (empty)

# Use cat -e to verify newlines
./aff_even "hello" | cat -e  # Should: hlo$
```

## 🐛 Debugging Tips

### If Output Doesn't Match

1. **Check newlines**
   ```bash
   # Use cat -e to see invisible chars
   ./test | cat -e
   ```

2. **Add debug prints** (for practice only!)
   ```c
   printf("DEBUG: i=%d, char='%c'\n", i, str[i]);
   ```

3. **Verify conditions**
   ```c
   // Test your boolean logic separately
   printf("Is %d even? %d\n", i, (i % 2 == 0));
   ```

4. **Check edge cases first**
   - Empty string
   - Single character
   - NULL pointer (if applicable)

## 📝 Creating Your Own Tests

Template for new test file:

```c
#include <unistd.h>
#include <stdio.h>

// Your solution function here
void your_function(char *str)
{
    // ...
}

void test_case(char *input, char *expected)
{
    printf("Input:    \"%s\"\n", input);
    printf("Expected: \"%s\"\n", expected);
    printf("Got:      \"");
    your_function(input);
    printf("\"\n---\n");
}

int main(void)
{
    printf("\n=== YOUR FUNCTION - Tests ===\n\n");
    
    test_case("test1", "expected1");
    test_case("test2", "expected2");
    // ... more tests
    
    printf("\nDone!\n");
    return (0);
}
```

## 🚀 Quick Test All Exercises

Bash script to test everything:

```bash
#!/bin/bash
# Save as: test_all.sh

exercises=("2-aff_even" "3-repeat_alpha" "4-fizzbuzz" "5-aff_odd" "6-alpha_mirror" "7-search_and_replace")

for ex in "${exercises[@]}"; do
    echo "========================================"
    echo "Testing: $ex"
    echo "========================================"
    cd "Exams Practice/Exam01/$ex"
    gcc -Wall -Wextra -Werror test_*.c -o test 2>/dev/null
    if [ $? -eq 0 ]; then
        ./test
        rm test
    else
        echo "Compilation failed!"
    fi
    cd - > /dev/null
    echo ""
done
```

## ✅ Pre-Exam Checklist

Before your exam, make sure you can:

- [ ] Compile with `-Wall -Wextra -Werror` (zero warnings)
- [ ] Handle `argc != expected` cases
- [ ] Print newline in ALL cases
- [ ] Handle empty strings
- [ ] Use only allowed functions (`write` only!)
- [ ] Test at least 3 different inputs manually
- [ ] Complete in under 10 minutes

## 📚 Additional Resources

- See individual exercise READMEs for concept explanations
- Check solution files for detailed comments
- Review `NEW_EXERCISES_TUTORIAL.md` for learning path

---

**Happy testing! 🎯**

*Remember: In real exams, you won't have test files. Practice until you can verify your solutions manually with confidence!*
