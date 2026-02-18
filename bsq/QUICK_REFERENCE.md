# BSQ Quick Reference Card

## 🎯 Project Goal
Find the **largest square** of empty cells in a map and mark it with the "full" character.

---

## 📋 Map Format
```
[ROWS][EMPTY][OBSTACLE][FULL]
[MAP CONTENT...]
```

**Example:**
```
9.ox
.o......o
...o..o..
.o.......
```

---

## 🔧 Allowed Functions
| Function | Purpose |
|----------|---------|
| `open` | Open files |
| `close` | Close files |
| `read` | Read from files/STDIN |
| `write` | Write to STDOUT/STDERR |
| `malloc` | Allocate memory |
| `free` | Free memory |
| `exit` | Exit program |

---

## 📦 Allowed Headers
```c
#include <unistd.h>    // read, write, close
#include <stdlib.h>    // malloc, free
#include <fcntl.h>     // open, O_RDONLY
```

**That's it! Only 3 headers!**

---

## ❌ Forbidden Items

### Functions
- `printf`, `fprintf`, `sprintf`
- `fopen`, `fclose`, `fread`, `fwrite`
- `strlen`, `strcpy`, `strcat`
- `memcpy`, `memset`, `realloc`
- `atoi`

### Control Structures
- `for` loops
- `do...while` loops
- `switch`/`case`
- `goto`
- Ternary operators (`?:`)

### Other
- VLAs (Variable Length Arrays)
- Global variables (unless const/static)
- More than 5 variables per function
- More than 4 parameters per function
- Functions longer than 25 lines

---

## 🧠 Algorithm (Dynamic Programming)

### Step 1: Convert Map to Matrix
```
Empty cell    → 1
Obstacle cell → 0
```

### Step 2: Fill Matrix (Bottom-Up)
```
For each cell from bottom-right to top-left:
    If obstacle: keep 0
    If on edge: keep 1
    Otherwise: value = min(right, below, diagonal) + 1
```

### Step 3: Find Maximum
```
Track the largest value and its position
```

### Step 4: Output
```
Print map with largest square marked
```

---

## 📊 Complexity
- **Time**: O(rows × cols)
- **Space**: O(rows × cols)

---

## 🧪 Test Categories

| Category | Count | Purpose |
|----------|-------|---------|
| Valid Maps | 15 | Basic functionality |
| Invalid Maps | 14 | Error handling |
| Stress Tests | 2 | Performance |
| STDIN | 2 | Input handling |
| Multiple Files | 1 | Multi-file |
| Memory Leaks | 1 | Memory mgmt |
| **Total** | **35** | **Complete** |

---

## 🐛 Common Bugs

### 1. Buffer Overflow
- **Cause**: No size limit on header
- **Fix**: Limit to 13 characters

### 2. Memory Leaks
- **Cause**: Missing `free()`
- **Fix**: Free all allocations

### 3. Off-by-One Errors
- **Cause**: Wrong boundaries
- **Fix**: Check `i < rows` not `i <= rows`

### 4. Segmentation Fault
- **Cause**: Null pointer or out of bounds
- **Fix**: Check pointers and bounds

---

## 🔍 Debug Commands

### Compile
```bash
make all
```

### Run Tests
```bash
./test_bsq.sh
```

### Check Memory
```bash
valgrind --leak-check=full ./bsq test_maps/test1_valid.txt
```

### Check Norm
```bash
norminette *.c *.h
```

### Debug with GDB
```bash
gcc -g *.c -o bsq
gdb ./bsq
(gdb) run test_maps/test1_valid.txt
(gdb) bt    # backtrace if crash
```

---

## ✅ Pre-Submission Checklist

- [ ] Compiles without warnings
- [ ] All tests pass
- [ ] No memory leaks
- [ ] Norminette clean
- [ ] No forbidden functions
- [ ] No forbidden headers
- [ ] Handles edge cases
- [ ] Works with STDIN
- [ ] Works with multiple files

---

## 📝 Error Messages

| Error | Cause |
|-------|-------|
| `map error` | Invalid map format |
| Segmentation fault | Memory access error |
| Timeout | Infinite loop or slow algorithm |
| Memory leak | Missing `free()` |

---

## 🎓 Key Concepts

### Dynamic Programming
- **Optimal Substructure**: Solution built from smaller solutions
- **Overlapping Subproblems**: Reuse computed values
- **Bottom-Up**: Start from base cases

### Memory Management
- **Allocate**: `malloc(size)`
- **Free**: `free(pointer)`
- **Order**: Free inner pointers first

### File I/O
- **Open**: `open(path, flags)`
- **Read**: `read(fd, buffer, size)`
- **Write**: `write(fd, buffer, size)`
- **Close**: `close(fd)`

---

## 🚀 Quick Start

```bash
# 1. Compile
make all

# 2. Test
./test_bsq.sh

# 3. Check memory
valgrind --leak-check=full ./bsq test_maps/test1_valid.txt

# 4. Check norm
norminette *.c *.h

# 5. Submit
git add .
git commit -m "Final submission"
git push
```

---

## 📚 File Structure

```
BSQ/
├── include/
│   └── bsq.h
├── src/
│   ├── main.c
│   ├── ft_create_map.c
│   ├── ft_get_matrix.c
│   ├── ft_process_map.c
│   └── ft_util.c
├── test_maps/
│   └── [30 test files]
├── Makefile
├── test_bsq.sh
└── [Documentation files]
```

---

## 💡 Tips

1. **Start Small**: Test with simple maps first
2. **Test Often**: Run tests after each change
3. **Check Memory**: Use valgrind regularly
4. **Follow Norm**: Fix violations immediately
5. **Handle Errors**: Validate all input
6. **Edge Cases**: Test single cell, all obstacles, etc.
7. **Performance**: Test large maps
8. **Clean Code**: Keep functions short and focused

---

## 🎯 Success = Understanding

Don't just pass tests - **understand**:
- Why the algorithm works
- How memory is managed
- What each function does
- How errors are handled
- Why Norm matters

---

**Good luck! 🍀**

Remember: Quality > Speed
Understanding > Copying
Learning > Passing
