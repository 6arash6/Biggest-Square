#!/bin/bash

# Script to push CI/CD changes to repository

echo "🚀 Pushing CI/CD files to repository..."
echo ""

# Stage all new files
echo "📦 Staging files..."
git add .github/ .gitignore README.md QUICKREF.md setup.sh install-hooks.sh .git-hooks/

# Show what will be committed
echo ""
echo "📋 Files to be committed:"
git status --short

# Commit
echo ""
echo "💾 Committing changes..."
git commit -m "Add CI/CD pipeline with GitHub Actions

- Add automated testing workflow (norminette, compilation, mini-moulinette)
- Add comprehensive setup script for dev environment
- Add pre-commit git hook for norminette checks
- Update README with badges and quick start guide
- Add QUICKREF guide for common commands
- Add CI/CD documentation guide
- Add .gitignore for build artifacts"

# Push to GitHub
echo ""
echo "⬆️  Pushing to GitHub..."
git push origin main

echo ""
echo "✅ Done! Check your GitHub repository:"
echo "   https://github.com/fhtw-dsc-inf/campus"
echo ""
echo "🔍 View Actions at:"
echo "   https://github.com/fhtw-dsc-inf/campus/actions"
