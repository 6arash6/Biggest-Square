# BSQ - Find the Biggest Square

## 📁 Project Structure

```
bsq/
├── Makefile              # Build configuration
├── include/
│   └── bsq.h             # Header file (Norm compliant)
├── src/
│   ├── main.c            # Entry point
│   ├── ft_create_map.c   # Map creation and cleanup
│   ├── ft_get_matrix.c   # Matrix parsing from file/stdin
│   ├── ft_get_line.c     # Line reading utility
│   ├── ft_process_map.c  # DP algorithm and output
│   └── ft_util.c         # Utility functions
├── test_maps/            # 30 test map files
├── test_bsq.sh           # Comprehensive test script
└── Documentation files
```

## 🔨 Compilation

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild from scratch
```

## 🚀 Usage

```bash
# From file
./bsq map_file

# From stdin
./bsq

# Multiple files
./bsq map1 map2 map3
```

## 📋 Map Format

```
[rows][empty_char][obstacle_char][full_char]
[map content...]
```

Example:
```
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
```

## 🧪 Testing

```bash
chmod +x test_bsq.sh
./test_bsq.sh ./bsq
```

## ✅ Norm Compliance

This solution follows the 42 Norm:
- ✅ Only allowed headers: `<unistd.h>`, `<stdlib.h>`, `<fcntl.h>`
- ✅ No ternary operators
- ✅ No `for` loops (using `while` instead)
- ✅ Proper 42 header comments
- ✅ Functions limited to 25 lines
- ✅ No more than 5 functions per file
- ✅ Only allowed external functions: `open`, `close`, `read`, `write`, `malloc`, `free`, `exit`

## 📚 Algorithm

Uses Dynamic Programming to find the largest square:
- Time complexity: O(n × m)
- Space complexity: O(n × m)

For each cell, calculate the maximum square size ending at that position:
```
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
```
