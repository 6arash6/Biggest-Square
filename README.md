# 42 Campus - Piscine C

![42 Tests](https://github.com/fhtw-dsc-inf/campus/actions/workflows/42-tests.yml/badge.svg)

This repository contains my solutions for the 42 Vienna Piscine C exercises.

## Structure

Each directory (C00-C13) contains:
- Exercise solutions (.c files)
- Assignment PDF (c**.pdf)

## Quick Start

### First Time Setup
```bash
# Run the automated setup script
bash setup.sh
source ~/.bashrc  # or ~/.zshrc if using zsh

# (Optional) Install git hooks for pre-commit checks
bash install-hooks.sh
```

### Documentation
- **[QUICKREF.md](QUICKREF.md)** - Quick reference for daily commands and tips
- **[HOW_IT_WORKS.md](HOW_IT_WORKS.md)** - Deep dive into how the automation works

## Testing

### Automated CI/CD
Every push triggers automated tests:
- ✅ **Norminette** - Code style validation
- ✅ **Compilation Check** - Ensures code compiles with `-Wall -Wextra -Werror`
- ✅ **Mini Moulinette** - Automated functional tests

Check status at: [Actions Tab](https://github.com/fhtw-dsc-inf/campus/actions)

### Local Testing

#### Norminette
```bash
norminette <file.c>
```

#### Mini Moulinette
```bash
cd C03  # or any assignment directory
mini C03
```

#### Manual Compilation
```bash
gcc -Wall -Wextra -Werror <file.c>
```

### Git Pre-Commit Hook
Install the pre-commit hook to automatically check norminette before commits:
```bash
bash install-hooks.sh
```

## Vim Setup

The repository includes 42header plugin configuration:
- Use `:Stdheader` in Vim to insert standard 42 header
- Configured for: Arash Javan Mojarad (ajavan-m@student.42vienna.com)

## Tools Used

- [Norminette](https://github.com/42School/norminette) - 42 coding style checker
- [Mini Moulinette](https://github.com/k11q/mini-moulinette) - Automated test runner
- [42header](https://github.com/42Paris/42header) - Vim header plugin

## How It Works

Want to understand how the automation works under the hood?

See **[HOW_IT_WORKS.md](HOW_IT_WORKS.md)** for a comprehensive explanation of:
- 🔧 Setup script internals
- 🪝 Git hooks mechanics
- 🤖 CI/CD pipeline workflow
- 🧪 Testing tools deep dive
- 📊 Architecture diagrams

## Author

**Arash Javan Mojarad** - 42 Vienna
- Email: ajavan-m@student.42vienna.com

---

*Note: This is a learning repository for 42 School exercises.*