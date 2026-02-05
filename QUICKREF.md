# 42 Campus - Quick Reference Guide

## 🚀 Quick Start

### First Time Setup
```bash
bash setup.sh
source ~/.bashrc  # or ~/.zshrc
```

## 📝 Common Commands

### Norminette (Style Check)
```bash
# Check single file
norminette file.c

# Check all files in directory
norminette

# Check specific directory
norminette C03/
```

### Mini Moulinette (Automated Tests)
```bash
# Navigate to assignment directory
cd C03

# Run tests
mini C03
```

### Compilation
```bash
# Basic compilation
gcc file.c

# With flags (42 standard)
gcc -Wall -Wextra -Werror file.c

# With custom output name
gcc -Wall -Wextra -Werror file.c -o myprogram
```

## 📋 Vim Commands

### 42 Header
```vim
:Stdheader    " Insert 42 header at top of file
```

### Useful Vim Shortcuts
```vim
F1            " Insert header (if mapped in .vimrc)
:w            " Save file
:q            " Quit
:wq           " Save and quit
u             " Undo
Ctrl+r        " Redo
```

## 🔍 Testing Workflow

1. **Write your code**
   ```bash
   vim ex00/ft_function.c
   ```

2. **Check style**
   ```bash
   norminette ex00/ft_function.c
   ```

3. **Compile and test**
   ```bash
   gcc -Wall -Wextra -Werror ex00/ft_function.c
   ./a.out
   ```

4. **Run automated tests**
   ```bash
   mini C03
   ```

5. **Commit if all pass**
   ```bash
   git add .
   git commit -m "Complete C03 ex00"
   git push
   ```

## 🤖 GitHub Actions CI/CD

Every push automatically runs:
- ✅ Norminette on all .c files
- ✅ Compilation check with -Wall -Wextra -Werror
- ✅ Mini Moulinette tests (C00-C08)

Check status: https://github.com/fhtw-dsc-inf/campus/actions

## 🐛 Debugging Common Issues

### Norminette Errors

**PREPROC_START_LINE**
- Preprocessor statements (#include) must be at column 1
- Remove any spaces before #include

**DECL_ASSIGN_LINE**
- Separate declaration and assignment
- Bad: `int x = 5;`
- Good: `int x;` then `x = 5;`

**LINE_TOO_LONG**
- Maximum 80 characters per line
- Split long lines

**WRONG_SCOPE_COMMENT**
- No C++ style comments (//) inside functions
- Use only C style comments (/* */)

### Compilation Errors

**Implicit function declaration**
- Add proper function prototypes
- Include necessary headers

**Undefined reference**
- Link all required .c files
- Example: `gcc file1.c file2.c`

**Segmentation fault**
- Check pointer initialization
- Verify array bounds
- Use null pointer checks

## 📊 Assignment Progress Tracking

| Assignment | Status | Norminette | Tests |
|------------|--------|------------|-------|
| C00        | 🚧     | ⏳         | ⏳    |
| C01        | 🚧     | ⏳         | ⏳    |
| C02        | 🚧     | ⏳         | ⏳    |
| C03        | 🚧     | ✅         | ⏳    |
| C04        | 📝     | ⏳         | ⏳    |
| C05        | 📝     | ⏳         | ⏳    |

Legend:
- 📝 Not started
- 🚧 In progress  
- ✅ Complete
- ⏳ Pending

## 🔗 Useful Links

- [42 Norminette](https://github.com/42School/norminette)
- [Mini Moulinette](https://github.com/k11q/mini-moulinette)
- [42 Header Plugin](https://github.com/42Paris/42header)
- [C Programming Guide](https://beej.us/guide/bgc/)

## 💡 Tips & Tricks

1. **Always run norminette** before committing
2. **Test edge cases** - empty strings, NULL pointers, INT_MIN/MAX
3. **Read the PDF** carefully - requirements are specific
4. **Use valgrind** for memory leak detection
5. **Comment your complex logic** (before functions only!)
6. **Git commit often** - save your progress frequently

## 🆘 Getting Help

- Check the PDF requirements
- Review mini-moulinette test cases
- Ask peers for debugging help
- Check GitHub Actions logs for CI failures
