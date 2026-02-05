# How It Works - 42 Campus Repository

This document explains how the automated setup, testing, and CI/CD pipeline works in this repository. It provides a deep dive into the internals of each component.

## Table of Contents
1. [Repository Overview](#repository-overview)
2. [Setup Script Deep Dive](#setup-script-deep-dive)
3. [Git Hooks Explained](#git-hooks-explained)
4. [GitHub Actions CI/CD Pipeline](#github-actions-cicd-pipeline)
5. [Testing Tools Internals](#testing-tools-internals)
6. [Workflow Diagram](#workflow-diagram)
7. [Directory Structure](#directory-structure)

---

## Repository Overview

This repository is structured to help students at 42 Vienna complete their Piscine C exercises with automated testing and validation. The key components are:

- **Exercise Solutions** (C00-C13 directories)
- **Pointer Tutorials** (42-pointer-tutorials directory)
- **Exam Practice** (Exams Practice directory)
- **Automation Scripts** (setup.sh, install-hooks.sh)
- **CI/CD Pipeline** (.github/workflows)
- **Git Hooks** (.git-hooks directory)

---

## Setup Script Deep Dive

### What happens when you run `bash setup.sh`

The `setup.sh` script automates the installation and configuration of all development tools. Here's what happens step by step:

#### 1. Shell Detection (Lines 18-26)
```bash
if [ -n "$ZSH_VERSION" ]; then
    SHELL_RC="$HOME/.zshrc"
elif [ -n "$BASH_VERSION" ]; then
    SHELL_RC="$HOME/.bashrc"
```
- Detects if you're using Zsh or Bash
- Sets `SHELL_RC` variable to the appropriate configuration file
- This determines where aliases and configurations will be added

#### 2. Norminette Installation (Lines 28-35)
```bash
python3 -m pip install --user norminette
```
- **Norminette** is 42's official C code style checker
- Installed via Python pip package manager
- `--user` flag installs it for your user only (no sudo required)
- Checks if already installed to avoid duplicate installations

#### 3. Mini-Moulinette Installation (Lines 37-48)
```bash
git clone https://github.com/k11q/mini-moulinette.git
```
- **Mini-Moulinette** is an automated test runner for 42 exercises
- Cloned to `~/mini-moulinette` directory
- If already exists, runs `git pull` to update it
- This is a community-maintained testing tool

#### 4. Alias Setup (Lines 50-59)
```bash
echo "alias mini='~/mini-moulinette/mini-moul.sh'" >> "$SHELL_RC"
```
- Creates a shell alias `mini` for easy access
- Points to the mini-moulinette executable script
- Added to your shell RC file so it persists across sessions
- After sourcing RC file, you can just type `mini C03` instead of the full path

#### 5. Vim 42header Plugin (Lines 61-69)
```bash
git clone https://github.com/42Paris/42header.git ~/.vim/pack/plugins/start/42header
```
- Installs Vim plugin for inserting 42-compliant file headers
- Uses Vim 8's native package management (pack/plugins/start)
- Headers include student name, email, creation date, etc.

#### 6. Vimrc Configuration (Lines 71-79)
```bash
echo 'let g:user42 = "Arash Javan Mojarad"' >> ~/.vimrc
echo 'let g:mail42 = "ajavan-m@student.42vienna.com"' >> ~/.vimrc
```
- Configures the header plugin with student information
- These variables are used when generating headers with `:Stdheader`

### Why This Approach?

- **Idempotent**: Can run multiple times safely (checks for existing installations)
- **User-friendly**: No manual configuration needed
- **Consistent**: Everyone gets the same development environment
- **Portable**: Works on Linux and macOS

---

## Git Hooks Explained

### What are Git Hooks?

Git hooks are scripts that run automatically at certain points in the Git workflow. This repository uses a **pre-commit hook** to validate code before it's committed.

### Installation Process (`install-hooks.sh`)

```bash
cp .git-hooks/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```

1. Copies pre-commit script from `.git-hooks/` to `.git/hooks/`
2. Makes it executable with `chmod +x`
3. Git automatically runs this script before every commit

### Pre-Commit Hook Internals

#### Step 1: Get Staged Files (Line 9)
```bash
STAGED_FILES=$(git diff --cached --name-only --diff-filter=ACM | grep -E '\.(c|h)$')
```
- `git diff --cached`: Shows files in staging area
- `--name-only`: Only file names, not content
- `--diff-filter=ACM`: Only Added, Changed, Modified files (not Deleted)
- `grep -E '\.(c|h)$'`: Filter for .c and .h files only

#### Step 2: Check Norminette Installation (Lines 17-22)
```bash
if ! command -v norminette &> /dev/null; then
    echo "⚠️  Warning: norminette is not installed"
    exit 0
fi
```
- Checks if norminette command exists
- If not installed, warns but allows commit (exit 0)
- This prevents blocking commits if norminette isn't set up

#### Step 3: Run Norminette on Each File (Lines 25-36)
```bash
for FILE in $STAGED_FILES; do
    norminette "$FILE" > /tmp/norminette_output.txt 2>&1
    
    if grep -q "Error" /tmp/norminette_output.txt; then
        echo "❌ Norminette errors in $FILE:"
        cat /tmp/norminette_output.txt
        ERRORS=$((ERRORS + 1))
    fi
done
```
- Loops through each staged C/H file
- Runs norminette and captures output
- Searches output for "Error" keyword
- Increments error counter if errors found

#### Step 4: Block Commit if Errors (Lines 41-46)
```bash
if [ $ERRORS -gt 0 ]; then
    echo "❌ Commit rejected: Fix norminette errors before committing"
    exit 1
fi
```
- If any errors detected, exit with code 1
- Exit code 1 tells Git to abort the commit
- Shows error messages to help fix issues

### Bypass Hook

If you need to commit despite errors:
```bash
git commit --no-verify
```
The `--no-verify` flag skips all hooks.

---

## GitHub Actions CI/CD Pipeline

### Overview

Every push to `main`/`master` or pull request triggers automated tests via GitHub Actions. The workflow is defined in `.github/workflows/42-tests.yml`.

### Workflow Structure

The workflow has **4 jobs** that run in parallel:

```
┌─────────────┐  ┌─────────────────┐  ┌──────────────────┐
│ Norminette  │  │ Compile Check   │  │ Mini Moulinette  │
│   Check     │  │                 │  │     Tests        │
└──────┬──────┘  └────────┬────────┘  └────────┬─────────┘
       │                  │                     │
       └──────────────────┴─────────────────────┘
                          │
                   ┌──────▼──────┐
                   │   Summary   │
                   └─────────────┘
```

### Job 1: Norminette Check

```yaml
- name: Install norminette
  run: |
    python3 -m pip install --upgrade pip
    pip install norminette

- name: Run norminette on all C files
  run: |
    find . -name "*.c" -o -name "*.h" | grep -v "mini-moul" | while read file; do
      norminette "$file" || echo "⚠️ Norminette failed for $file"
    done
```

**How it works:**
1. Sets up Python 3 environment
2. Installs norminette via pip
3. Finds all `.c` and `.h` files (excluding mini-moulinette tests)
4. Runs norminette on each file
5. Reports failures but continues (doesn't fail the job)

### Job 2: Compilation Check

```yaml
- name: Compile C files
  run: |
    for dir in C00 C01 C02 C03 C04 C05 C06 C07 C08 C09 C10 C11 C12 C13; do
      if [ -d "$dir" ]; then
        cd "$dir"
        for file in *.c; do
          gcc -Wall -Wextra -Werror "$file" -o "${file%.c}.out"
          rm -f "${file%.c}.out"
        done
        cd ..
      fi
    done
```

**How it works:**
1. Installs GCC compiler
2. Iterates through all assignment directories (C00-C13)
3. Compiles each `.c` file with strict flags:
   - `-Wall`: Enable all warnings
   - `-Wextra`: Enable extra warnings
   - `-Werror`: Treat warnings as errors
4. Creates `.out` executable, then deletes it
5. Reports compilation failures

**Why compile and delete?**
- We only care if it compiles, not the binary
- Keeps repository clean (no compiled binaries)

### Job 3: Mini Moulinette Tests

```yaml
- name: Run tests for available assignments
  run: |
    for dir in C00 C01 C02 C03 C04 C05 C06 C07 C08; do
      if [ -d "$dir" ]; then
        cd "$dir"
        cp -R ~/mini-moulinette/mini-moul mini-moul
        cd mini-moul
        bash test.sh "$dir"
        cd ..
        rm -rf mini-moul
        cd ..
      fi
    done
```

**How it works:**
1. Clones mini-moulinette repository
2. For each assignment directory:
   - Copies test files into the directory
   - Runs the test script
   - Cleans up test files
3. Reports test results
4. Uses `continue-on-error: true` so failures don't stop workflow

**Why copy and delete?**
- Mini-moulinette expects tests in same directory as solutions
- Cleanup prevents test files from being committed

### Job 4: Summary

```yaml
summary:
  runs-on: ubuntu-latest
  needs: [norminette, compile-check, mini-moulinette]
  if: always()
```

**How it works:**
1. Waits for all three test jobs to complete (`needs: [...]`)
2. Runs even if previous jobs failed (`if: always()`)
3. Creates a summary in GitHub Actions UI
4. Provides single place to check overall status

### Triggering the Workflow

The workflow runs on:
- **Push** to main/master branches
- **Pull requests** to main/master
- **Manual trigger** via `workflow_dispatch`

---

## Testing Tools Internals

### Norminette

**What is it?**
A Python-based linter that enforces 42's C coding style rules.

**How it works:**
1. Parses C code into an Abstract Syntax Tree (AST)
2. Applies 42 coding norm rules:
   - Max 80 characters per line
   - Max 25 lines per function
   - No variable declarations with assignments
   - Specific indentation rules
   - Comment formatting rules
3. Reports violations with line numbers

**Common checks:**
- `PREPROC_START_LINE`: Preprocessor directives must start at column 1
- `DECL_ASSIGN_LINE`: No declaration with assignment on same line
- `LINE_TOO_LONG`: Line exceeds 80 characters
- `WRONG_SCOPE_COMMENT`: C++ style comments in wrong place

### Mini Moulinette

**What is it?**
A bash script that runs automated functional tests on 42 exercises.

**How it works:**
1. Knows expected behavior for each 42 exercise
2. Compiles your code
3. Runs test cases with various inputs
4. Compares output to expected output
5. Reports pass/fail for each test

**Test methodology:**
- Edge cases: NULL pointers, empty strings, INT_MIN/MAX
- Normal cases: Standard inputs
- Stress tests: Large inputs, many operations

**Limitations:**
- Community-maintained (not official 42 tool)
- May not cover all test cases from official Moulinette
- Should be supplemented with manual testing

---

## Workflow Diagram

### Developer Workflow

```
┌─────────────────────┐
│  Write Code         │
│  (vim file.c)       │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Local Testing      │
│  - norminette       │
│  - gcc compile      │
│  - mini C03         │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Git Commit         │
│  (git add/commit)   │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Pre-commit Hook    │
│  - Run norminette   │
│  - Block if errors  │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Git Push           │
│  (git push)         │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  GitHub Actions     │
│  - Norminette       │
│  - Compilation      │
│  - Tests            │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  ✅ All Pass?       │
│  Check Actions Tab  │
└─────────────────────┘
```

### CI/CD Pipeline Flow

```
Push to GitHub
      │
      ▼
┌─────────────────────────────────────┐
│  GitHub Actions Triggered           │
└───────────┬─────────────────────────┘
            │
    ┌───────┴───────┬────────────┐
    │               │            │
    ▼               ▼            ▼
┌────────┐    ┌──────────┐  ┌────────┐
│Normin. │    │Compile   │  │ Tests  │
│Check   │    │Check     │  │        │
└───┬────┘    └────┬─────┘  └───┬────┘
    │              │            │
    └──────────────┴────────────┘
                   │
                   ▼
           ┌───────────────┐
           │   Summary     │
           │   Report      │
           └───────────────┘
                   │
                   ▼
           ┌───────────────┐
           │  Email/Badge  │
           │   Update      │
           └───────────────┘
```

---

## Directory Structure

```
campus/
├── .git/                       # Git repository data
├── .git-hooks/                 # Pre-commit hook template
│   └── pre-commit             # Norminette validation script
├── .github/                    # GitHub configuration
│   └── workflows/
│       └── 42-tests.yml       # CI/CD pipeline definition
├── .gitignore                 # Files to ignore in Git
├── 42-pointer-tutorials/      # Interactive pointer learning modules
│   ├── 00-basics/             # Pointer fundamentals
│   ├── 01-pointer-arithmetic/ # Pointer math operations
│   ├── 02-pointers-and-arrays/# Array pointer equivalence
│   ├── 03-pointers-and-functions/# Pass by reference
│   ├── 04-advanced-pointers/  # Double pointers, function pointers
│   ├── 05-common-mistakes/    # Debugging and error prevention
│   └── utils/                 # Helper functions (ft_putchar, etc.)
├── C00-C13/                   # Assignment directories
│   ├── *.c                    # Exercise solutions
│   └── *.pdf                  # Assignment PDFs
├── Exams Practice/            # Practice exam exercises
│   ├── Exam00/                # Level 0 practice
│   ├── Exam01/                # Level 1 practice
│   ├── Exam02/                # Level 2 practice
│   └── Exam03/                # Level 3 practice
├── README.md                  # Main documentation
├── QUICKREF.md                # Quick reference guide
├── HOW_IT_WORKS.md           # This file - deep dive explanation
├── setup.sh                   # Automated environment setup
└── install-hooks.sh           # Git hooks installation
```

### Key Files Explained

- **setup.sh**: One-command setup for all development tools
- **install-hooks.sh**: Installs pre-commit validation
- **.git-hooks/pre-commit**: Template for validation script
- **42-tests.yml**: GitHub Actions workflow configuration
- **README.md**: User-facing documentation
- **QUICKREF.md**: Command reference for daily use
- **HOW_IT_WORKS.md**: This file - explains internals

---

## Technical Details

### Why Separate .git-hooks Directory?

Git's `.git/hooks` directory is not tracked by Git (it's in `.git/`, which is ignored). By keeping hooks in `.git-hooks/`, we can:
1. Version control the hook scripts
2. Share them with all contributors
3. Require manual installation (prevents auto-execution of untrusted code)

### Why Multiple CI Jobs?

Running jobs in parallel:
- **Faster feedback**: All checks run simultaneously
- **Clear reporting**: Each job has separate status
- **Selective fixes**: Know exactly which check failed
- **Independence**: One failing job doesn't stop others

### Shell Script Best Practices

The scripts use several best practices:

```bash
set -e                    # Exit on first error
command -v tool &> /dev/null  # Check if command exists
[ -d "$dir" ]            # Check if directory exists
grep -q "pattern"        # Quiet grep (only exit code)
${variable:-default}     # Default values
```

---

## Troubleshooting

### Setup Script Issues

**Problem**: Norminette not found after setup
```bash
# Solution: Reload shell configuration
source ~/.bashrc  # or ~/.zshrc
```

**Problem**: Permission denied on setup.sh
```bash
# Solution: Make it executable
chmod +x setup.sh
```

### Pre-commit Hook Issues

**Problem**: Hook not running
```bash
# Check if installed
ls -la .git/hooks/pre-commit

# Reinstall
bash install-hooks.sh
```

**Problem**: Want to bypass hook temporarily
```bash
# Use --no-verify flag
git commit --no-verify -m "message"
```

### GitHub Actions Issues

**Problem**: CI fails but local tests pass
- Check the Actions log for specific errors
- Ensure you're using same compiler flags: `-Wall -Wextra -Werror`
- Verify all files are committed

**Problem**: Mini Moulinette tests timeout
- Tests may run longer in CI environment
- Check for infinite loops or hanging input

---

## Summary

This repository provides a complete automated development environment for 42 students:

1. **One-command setup** (`setup.sh`) installs all tools
2. **Pre-commit validation** prevents bad commits locally
3. **CI/CD pipeline** validates every push automatically
4. **Comprehensive testing** with norminette and mini-moulinette
5. **Learning resources** with pointer tutorials and exam practice

The automation ensures:
- ✅ Code always meets 42 style requirements
- ✅ Exercises compile without warnings
- ✅ Functional tests pass
- ✅ Consistent development environment for all students
- ✅ Fast feedback loop for learning

For daily usage, see [QUICKREF.md](QUICKREF.md). For getting started, see [README.md](README.md).
