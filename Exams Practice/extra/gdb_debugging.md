# GDB Debugging Steps (Alternative to LLDB)

If you can't use LLDB, GDB is a powerful alternative for C debugging and is often pre-installed.

---

## How to Use GDB with the Example

1. **Compile with debug info:**
   ```sh
   gcc -g lldb_debug_example.c -o lldb_debug_example
   ```
2. **Start GDB:**
   ```sh
   gdb ./lldb_debug_example
   ```
3. **At the (gdb) prompt:**
   - `break main` — set a breakpoint at main
   - `run` — start the program
   - `next` — step to next line
   - `print arr` — print the array pointer
   - `print str` — print the string
   - `print p` — print the pointer
   - `bt` — show backtrace (call stack)
   - `quit` — exit gdb

---

## Example GDB Session
```
(gdb) break main
(gdb) run
(gdb) next
(gdb) print arr
(gdb) print str
(gdb) print p
(gdb) bt
```

---

## Tips
- Use `next` to step over lines, `step` to step into functions.
- Use `print arr[0]` or `x/5d arr` to see array contents.
- If the program crashes, use `bt` to see where.
- You can set breakpoints at any function or line: `break 15` (for line 15).

---

**GDB works almost identically to LLDB for most C debugging tasks!**
