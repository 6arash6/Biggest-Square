# BSQ Debugging Quick Reference

> Update (2026-02-18): code refactored and norminette-clean; documentation and test fixtures updated. Tests: **35/35** passing; valgrind: **no leaks**. See `CHANGELOG.md` for details.

## Common Issues and Solutions

### 1. SEGMENTATION FAULT

#### Symptoms
- Program crashes with "Segmentation fault"
- Exit code 139

#### Common Causes
1. **Array out of bounds**
   ```c
   // WRONG
   for (int i = 0; i <= rows; i++)  // Should be i < rows

   // CORRECT
   for (int i = 0; i < rows; i++)
   ```

2. **Null pointer dereference**
   ```c
   // WRONG
   free(map->matrix[i]);  // What if matrix[i] is NULL?

   // CORRECT
   if (map->matrix[i])
       free(map->matrix[i]);
   ```

3. **Uninitialized pointers**
   ```c
   // WRONG
   char *str;
   str[0] = 'a';  // str is not allocated!

   // CORRECT
   char *str = malloc(2);
   str[0] = 'a';
   str[1] = '\0';
   ```

#### How to Debug
```bash
# Compile with debug symbols
gcc -g -Wall -Wextra -Werror *.c -o bsq

# Run with gdb
gdb ./bsq
(gdb) run test_maps/test1_valid.txt
(gdb) bt  # Show backtrace when it crashes
```

---

### 2. MEMORY LEAKS

#### Symptoms
- Valgrind shows "LEAK SUMMARY"
- Memory usage grows over time

#### Common Causes
1. **Missing free()**
   ```c
   // WRONG
   char *buffer = malloc(100);
   // ... use buffer ...
   return;  // Forgot to free!

   // CORRECT
   char *buffer = malloc(100);
   // ... use buffer ...
   free(buffer);
   return;
   ```

2. **Free in wrong order**
   ```c
   // WRONG
   free(map);           // Free struct first
   free(map->matrix);   // Can't access map->matrix anymore!

   // CORRECT
   free(map->matrix);   // Free inner pointer first
   free(map);           // Then free struct
   ```

#### How to Debug
```bash
# Run with valgrind
valgrind --leak-check=full --show-leak-kinds=all ./bsq test_maps/test1_valid.txt

# Look for:
# ==12345== LEAK SUMMARY:
# ==12345==    definitely lost: 100 bytes in 1 blocks
```

---

### 3. INFINITE LOOP

#### Symptoms
- Program hangs
- Timeout in tests

#### Common Causes
1. **Wrong loop condition**
   ```c
   // WRONG
   while (i > 0)  // Should be i >= 0

   // CORRECT
   while (i >= 0)
   ```

2. **Missing increment**
   ```c
   // WRONG
   while (i < rows)
   {
       // ... do something ...
       // Forgot i++!
   }

   // CORRECT
   while (i < rows)
   {
       // ... do something ...
       i++;
   }
   ```

#### How to Debug
```bash
# Add debug prints
printf("Loop iteration: %d\n", i);

# Or use gdb
gdb ./bsq
(gdb) break main.c:42  # Set breakpoint at line 42
(gdb) run test_maps/test1_valid.txt
(gdb) continue  # Continue to next breakpoint
```

---

### 4. WRONG OUTPUT

#### Symptoms
- Square in wrong position
- Wrong square size
- Missing characters

#### Common Causes
1. **Off-by-one error**
   ```c
   // WRONG
   int finish = start + size;  // Should be size - 1

   // CORRECT
   int finish = start + size - 1;
   ```

2. **Wrong comparison**
   ```c
   // WRONG
   if (a < b && a < c)  // Should be <=

   // CORRECT
   if (a <= b && a <= c)
   ```

3. **Wrong character printed**
   ```c
   // WRONG
   write(1, &map->empty, 1);  // Should print full character

   // CORRECT
   write(1, &map->full, 1);
   ```

#### How to Debug
```bash
# Add debug prints
printf("Square size: %d at (%d, %d)\n", size, row, col);

# Print matrix values
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols; j++)
        printf("%d ", matrix[i][j]);
    printf("\n");
}
```

---

### 5. "MAP ERROR" FOR VALID MAPS

#### Symptoms
- Valid map shows "map error"
- Should succeed but fails

#### Common Causes
1. **Wrong validation logic**
   ```c
   // WRONG
   if (buffer != empty || buffer != obstacle)  // Always true!
       return (1);

   // CORRECT
   if (buffer != empty && buffer != obstacle)
       return (1);
   ```

2. **Missing newline check**
   ```c
   // WRONG
   if (buffer != empty && buffer != obstacle)
       return (1);  // Newline is not empty or obstacle!

   // CORRECT
   if (buffer != empty && buffer != obstacle && buffer != '\n')
       return (1);
   ```

3. **Wrong return value**
   ```c
   // WRONG
   return (0);  // 0 means error in some functions

   // CORRECT
   return (1);  // Check function's convention
   ```

#### How to Debug
```bash
# Add debug prints in validation functions
printf("Validating: buffer='%c' empty='%c' obstacle='%c'\n", 
       buffer, map->empty, map->obstacle);

# Check return values
printf("ft_map_header returned: %d\n", result);
```

---

### 6. NORM VIOLATIONS

#### Symptoms
- Norminette shows errors
- Evaluation fails

#### Common Violations
1. **Ternary operator**
   ```c
   // WRONG
   int x = (a > b) ? a : b;

   // CORRECT
   int x;
   if (a > b)
       x = a;
   else
       x = b;
   ```

2. **For loop**
   ```c
   // WRONG
   for (int i = 0; i < n; i++)

   // CORRECT
   int i;
   i = 0;
   while (i < n)
   {
       // ...
       i++;
   }
   ```

3. **More than 5 variables**
   ```c
   // WRONG
   int a, b, c, d, e, f;  // 6 variables!

   // CORRECT
   // Split into multiple functions or use struct
   ```

#### How to Check
```bash
# Run norminette
norminette *.c *.h

# Fix all errors before submission
```

---

### 7. COMPILATION ERRORS

#### Symptoms
- Make fails
- Undefined references

#### Common Causes
1. **Missing function prototype**
   ```c
   // In .h file
   int my_function(int x);  // Don't forget this!
   ```

2. **Wrong include**
   ```c
   // WRONG
   #include <stdio.h>  // Not allowed!

   // CORRECT
   #include <unistd.h>
   ```

3. **Missing source file in Makefile**
   ```makefile
   # WRONG
   SRC = src/main.c src/util.c  # Missing other files!

   # CORRECT
   SRC = src/main.c src/util.c src/create_map.c src/get_matrix.c \
        src/process_map.c
   ```

#### How to Debug
```bash
# Check compilation
make fclean
make all

# Look for warnings
gcc -Wall -Wextra -Werror *.c -o bsq
```

---

## Quick Debugging Checklist

Before submitting, check:

- [ ] Compiles without warnings
- [ ] No segmentation faults
- [ ] No memory leaks (valgrind)
- [ ] All tests pass
- [ ] Norminette clean
- [ ] Handles all edge cases
- [ ] Works with STDIN
- [ ] Works with multiple files
- [ ] No forbidden functions
- [ ] No forbidden headers

---

## Test-Driven Debugging

1. **Run test suite**
   ```bash
   ./test_bsq.sh
   ```

2. **Identify failing test**
   - Note the test name
   - Check the test file

3. **Isolate the problem**
   - Create minimal test case
   - Add debug prints
   - Use gdb if needed

4. **Fix the issue**
   - Make targeted fix
   - Don't change working code

5. **Verify fix**
   - Run failing test
   - Run all tests
   - Check for regressions

---

## Emergency Fixes

### If program crashes:
1. Check array bounds
2. Check null pointers
3. Check memory allocation
4. Use gdb backtrace

### If memory leaks:
1. Check all malloc have free
2. Check free order
3. Use valgrind --leak-check=full

### If wrong output:
1. Check algorithm logic
2. Check boundary conditions
3. Add debug prints

### If norm errors:
1. Run norminette
2. Fix each error
3. Re-run norminette

---

## Final Checklist

Before evaluation:

1. **Compile**
   ```bash
   make fclean && make all
   ```

2. **Test**
   ```bash
   ./test_bsq.sh
   ```

3. **Norm**
   ```bash
   norminette -R CheckForbiddenSourceHeader
   ```

4. **Memory**
   ```bash
   valgrind --leak-check=full ./bsq test_maps/test1_valid.txt
   ```

5. **Submit**
   ```bash
   git add .
   git commit -m "Final submission"
   git push
   ```

Good luck! 🍀
