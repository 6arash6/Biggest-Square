# BSQ - Find the Biggest Square

## 📁 Project Structure

```
bsq/
├── Makefile              # Build configuration
├── include/
│   └── bsq.h             # Header file (Norm compliant)
├── src/
│   ├── main.c
│   ├── ft_create_map.c
│   ├── ft_fill_matrix.c
│   ├── ft_free_map.c
│   ├── ft_get_line.c
│   ├── ft_get_matrix.c
│   ├── ft_mark_square.c
│   ├── ft_memory.c
│   ├── ft_parse_header.c
│   ├── ft_print_map.c
│   ├── ft_process_map.c
│   ├── ft_string.c
│   └── ft_util.c
├── test_maps/            # 35 test map files
├── test_bsq.sh           # Comprehensive test script
└── Documentation files
```

## � Recent changes (2026-02-18)

- Code refactored and split into smaller, Norm-compliant functions; all `bsq/` sources now pass `norminette`.
- Added/renamed source files: `ft_fill_matrix.c`, `ft_free_map.c`, `ft_mark_square.c`, `ft_memory.c`, `ft_parse_header.c`, `ft_print_map.c`, `ft_string.c`.
- Added missing test fixtures (total test maps: 35) including stress tests: `test15_large.txt` (100×100) and `test16_very_large.txt` (500×500).
- All tests pass: **35/35**. Valgrind: **no leaks**.
- Documentation updated (README, QUICK_REFERENCE, TEST_DOCUMENTATION, DEBUG_GUIDE, BSQ_COMPLETE_PACKAGE). See `CHANGELOG.md` for details.
- Commit will include Co‑authored‑by: Mina Zahir <mina-zahir@users.noreply.github.com>.

## �🔨 Compilation

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
