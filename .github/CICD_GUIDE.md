# GitHub Actions CI/CD Guide

## Overview

This repository includes automated testing via GitHub Actions. Every time you push code or create a pull request, automated tests run to verify your code quality.

## What Gets Tested?

### 1. Norminette Check ✅
- **What**: Validates all `.c` and `.h` files against 42 coding standards
- **When**: On every push and pull request
- **Files checked**: All C files except those in `mini-moul` directory
- **Failure**: Your code doesn't follow 42 norm (check job logs for details)

### 2. Compilation Check ✅
- **What**: Compiles all `.c` files with strict flags
- **Flags used**: `-Wall -Wextra -Werror`
- **When**: On every push and pull request
- **Files checked**: All C files in C00-C13 directories
- **Failure**: Code has compilation errors or warnings

### 3. Mini Moulinette Tests ✅
- **What**: Runs functional tests on your code
- **Coverage**: C00-C08 (where tests are available)
- **When**: On every push and pull request
- **Failure**: Your functions don't produce expected outputs

## Viewing Test Results

### GitHub Interface
1. Go to your repository: https://github.com/fhtw-dsc-inf/campus
2. Click on the "Actions" tab
3. Click on the latest workflow run
4. View individual job results

### Badge in README
The badge at the top of README.md shows:
- 🟢 Green "passing" - All tests passed
- 🔴 Red "failing" - Some tests failed
- 🟡 Yellow "running" - Tests in progress

## Understanding Failures

### Norminette Failures
```
Error: PREPROC_START_LINE (line: 13, col: 2)
```
**Fix**: Move `#include` statements to column 1 (no spaces before)

```
Error: DECL_ASSIGN_LINE (line: 18, col: 11)
```
**Fix**: Separate variable declaration and assignment:
```c
// Bad
int x = 5;

// Good
int x;
x = 5;
```

### Compilation Failures
```
error: implicit declaration of function 'ft_putchar'
```
**Fix**: Add function prototype or include header

```
warning: unused variable 'x'
```
**Fix**: Remove unused variables or use them

### Test Failures
```
⚠️ Tests failed for C03
```
**Fix**: 
1. Check the job logs for specific test failures
2. Run tests locally: `cd C03 && mini C03`
3. Review test cases in `~/mini-moulinette/mini-moul/tests/C03/`

## Workflow Files

### Location
`.github/workflows/42-tests.yml`

### Triggers
- Push to `main` or `master` branch
- Pull requests to `main` or `master` branch  
- Manual trigger via "Run workflow" button

### Jobs Structure
```yaml
norminette (runs norminette check)
    ↓
compile-check (verifies compilation)
    ↓
mini-moulinette (runs functional tests)
    ↓
summary (generates test summary)
```

## Customizing Workflows

### Add More Directories
Edit `.github/workflows/42-tests.yml`:
```yaml
# Add C09, C10, etc.
for dir in C00 C01 C02 C03 C04 C05 C06 C07 C08 C09 C10; do
```

### Skip Specific Files
Add to `.gitignore` or modify workflow:
```yaml
find . -name "*.c" | grep -v "skip-this-file.c" | ...
```

### Add Memory Leak Checks
Add valgrind job:
```yaml
valgrind:
  name: Memory Leak Check
  runs-on: ubuntu-latest
  steps:
    - uses: actions/checkout@v3
    - name: Install valgrind
      run: sudo apt-get install -y valgrind
    - name: Run valgrind
      run: |
        # Add your valgrind commands here
```

## Best Practices

### Before Pushing
1. ✅ Run norminette locally
2. ✅ Compile with `-Wall -Wextra -Werror`
3. ✅ Run mini-moulinette tests
4. ✅ Fix all issues before pushing

### During Development
1. Commit frequently with descriptive messages
2. Check CI results after each push
3. Fix failures immediately
4. Don't merge PRs with failing tests

### When Tests Fail
1. 📖 Read the error messages carefully
2. 🔍 Check job logs for details
3. 🧪 Reproduce locally
4. 🔧 Fix and push again
5. ✅ Verify tests pass

## Manual Workflow Trigger

### Via GitHub Interface
1. Go to Actions tab
2. Select "42 Campus Tests" workflow
3. Click "Run workflow" button
4. Select branch
5. Click "Run workflow"

### Why Manual Trigger?
- Test without pushing new commits
- Re-run failed tests
- Verify fixes before pushing

## Troubleshooting

### "Workflow not found"
- Ensure `.github/workflows/42-tests.yml` exists
- Check file is properly committed and pushed

### "Permission denied"
- Workflow requires Actions to be enabled
- Check repository settings → Actions → Allow all actions

### "Tests take too long"
- Normal runtime: 2-5 minutes
- If stuck: Cancel and restart workflow
- Check for infinite loops in code

## Advanced: Workflow Secrets

For future enhancements (API keys, tokens):
1. Go to Settings → Secrets and variables → Actions
2. Click "New repository secret"
3. Use in workflow: `${{ secrets.SECRET_NAME }}`

## Resources

- [GitHub Actions Documentation](https://docs.github.com/en/actions)
- [Workflow Syntax](https://docs.github.com/en/actions/reference/workflow-syntax-for-github-actions)
- [Status Badge](https://docs.github.com/en/actions/monitoring-and-troubleshooting-workflows/adding-a-workflow-status-badge)

## Questions?

- Check the [QUICKREF.md](QUICKREF.md) for general commands
- Review workflow logs for specific errors
- Test locally before pushing

---

**Remember**: CI/CD is here to help you catch issues early. Don't fight it, embrace it! 🚀
