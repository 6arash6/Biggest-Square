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

## Implementation Steps

This section documents the steps taken to set up the repository, configure the AI chat system, convert PDFs to Markdown, and implement C exercises.

### 1. Git LFS Setup
- **Issue**: Repository configured for Git LFS but `git-lfs` not found on PATH.
- **Solution**: Installed Git LFS on Alpine Linux.
- **Commands**:
  ```bash
  sudo apk add --no-cache git-lfs
  git lfs install
  git lfs version
  ```

### 2. Branch Management
- **Issue**: Needed to switch to `main` branch for updates.
- **Solution**: Fetched and pulled from origin/main.
- **Commands**:
  ```bash
  git fetch origin
  git pull --ff-only origin main
  ```

### 3. SSH Authentication Setup
- **Issue**: Push failed due to SSH permission denied.
- **Solution**: Generated SSH key, added to GitHub, configured remote.
- **Commands**:
  ```bash
  ssh-keygen -t ed25519 -C "6arash6@users.noreply.github.com" -f ~/.ssh/id_ed25519 -N ""
  # Add pub key to GitHub SSH keys
  eval "$(ssh-agent -s)"
  ssh-add ~/.ssh/id_ed25519
  ssh -T git@github.com
  git remote set-url origin git@github.com:fhtw-dsc-inf/campus.git
  git push origin main
  ```

### 4. AI Chat System Setup
- **Issue**: chat.py had syntax errors and missing model.
- **Solution**: Fixed syntax, downloaded DeepSeek model, updated for Markdown.
- **Changes**:
  - Fixed `Web Search` to `web_search`.
  - Downloaded `deepseek-coder-6.7b-instruct.Q4_K_M.gguf`.
  - Updated MODEL_PATH and loading message.
  - Changed to load MD files for RAG.
  - Disabled streaming for faster output.
- **Commands**:
  ```bash
  mkdir -p models
  curl -L -o models/deepseek-coder-6.7b-instruct.Q4_K_M.gguf "https://huggingface.co/TheBloke/DeepSeek-Coder-6.7B-Instruct-GGUF/resolve/main/deepseek-coder-6.7b-instruct.Q4_K_M.gguf"
  python chat.py
  ```

### 5. PDF to Markdown Conversion
- **Issue**: Needed Markdown for AI context.
- **Solution**: Used pdftotext to convert PDFs to MD.
- **Note**: Text-only; images not included.
- **Commands**:
  ```bash
  sudo apk add --no-cache poppler-utils
  for i in {00..13}; do pdftotext C$i/c$i.pdf C$i/c$i.md; done
  ```

### 6. C Exercises Implementation (C06)
- **Issue**: Needed to solve C06 exercises.
- **Solution**: Read C06/c06.md, implemented C code.
- **Files**: `C06/ex00/` to `C06/ex03/` with .c files.
- **Testing**:
  ```bash
  cd C06/ex00
  cc -Wall -Wextra -Werror ft_print_program_name.c
  ./a.out
  ```

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