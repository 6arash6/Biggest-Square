#!/bin/bash

# Install git hooks for the repository

echo "Installing git hooks..."

# Copy pre-commit hook
cp .git-hooks/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit

echo "✅ Pre-commit hook installed!"
echo ""
echo "The hook will:"
echo "  - Run norminette on all staged .c and .h files"
echo "  - Prevent commits if norminette finds errors"
echo ""
echo "To bypass the hook: git commit --no-verify"
