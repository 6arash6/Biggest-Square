# Debugging and Memory Checking: Valgrind & LLDB

## 1. Valgrind: Memory Leak Checker

### What is Valgrind?
Valgrind is a tool to detect memory leaks, invalid memory access, and improper use of malloc/free in C programs.

### How to Use
1. Compile with debug info: `gcc -g yourfile.c -o yourprog`
2. Run: `valgrind ./yourprog [args]`

### Example Output
```
==1234== Memcheck, a memory error detector
==1234== LEAK SUMMARY:
==1234==    definitely lost: 8 bytes in 1 blocks
==1234==    ...
```

### Common Issues Detected
- Memory leaks (forgot to free)
- Invalid read/write (out-of-bounds, use after free)
- Double free

### Typical Fixes
- Always free what you malloc
- Never access memory after free
- Check array bounds

---

## 2. LLDB: Debugger for C

### What is LLDB?
LLDB is a debugger (like gdb) for C/C++ programs. It lets you step through code, inspect variables, and find bugs.

### How to Use
1. Compile with debug info: `gcc -g yourfile.c -o yourprog`
2. Start: `lldb ./yourprog`
3. At the (lldb) prompt:
   - `run [args]` — start the program
   - `break main` — set a breakpoint at main
   - `next` — step to next line
   - `print var` — print value of variable `var`
   - `bt` — show backtrace (call stack)
   - `quit` — exit lldb

### Example Session
```
(lldb) break main
(lldb) run
(lldb) next
(lldb) print i
(lldb) bt
```

### Tips
- Use breakpoints to stop at functions or lines
- Use `print` to inspect variables and pointers
- Use `bt` to debug crashes (segfaults)

---

## 3. When to Use
- **Valgrind:** After every malloc/free exercise, before submitting code
- **LLDB:** When your program crashes, or you want to understand logic step-by-step

---

**Mastering these tools will make you a much better C programmer!**
