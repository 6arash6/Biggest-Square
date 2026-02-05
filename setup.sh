#!/bin/bash

# 42 Campus Development Environment Setup Script
# This script sets up all necessary tools for 42 assignments

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}42 Campus Environment Setup${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""

# Detect shell
SHELL_RC=""
if [ -n "$ZSH_VERSION" ]; then
    SHELL_RC="$HOME/.zshrc"
elif [ -n "$BASH_VERSION" ]; then
    SHELL_RC="$HOME/.bashrc"
else
    echo -e "${YELLOW}Warning: Could not detect shell type${NC}"
fi

# Install norminette
echo -e "${YELLOW}[1/4] Installing norminette...${NC}"
if command -v norminette &> /dev/null; then
    echo -e "${GREEN}✓ Norminette already installed${NC}"
else
    python3 -m pip install --user norminette
    echo -e "${GREEN}✓ Norminette installed${NC}"
fi

# Install mini-moulinette
echo -e "${YELLOW}[2/4] Installing mini-moulinette...${NC}"
if [ -d "$HOME/mini-moulinette" ]; then
    echo -e "${GREEN}✓ Mini-moulinette already installed${NC}"
    cd ~/mini-moulinette
    git pull
    cd - > /dev/null
else
    cd ~
    git clone https://github.com/k11q/mini-moulinette.git
    echo -e "${GREEN}✓ Mini-moulinette installed${NC}"
fi

# Set up alias
if [ -n "$SHELL_RC" ]; then
    echo -e "${YELLOW}[3/4] Setting up mini alias...${NC}"
    if grep -q "alias mini=" "$SHELL_RC"; then
        echo -e "${GREEN}✓ Alias already exists${NC}"
    else
        echo "alias mini='~/mini-moulinette/mini-moul.sh'" >> "$SHELL_RC"
        echo -e "${GREEN}✓ Alias added to $SHELL_RC${NC}"
    fi
fi

# Install vim header plugin
echo -e "${YELLOW}[4/4] Installing 42header Vim plugin...${NC}"
if [ -d "$HOME/.vim/pack/plugins/start/42header" ]; then
    echo -e "${GREEN}✓ 42header already installed${NC}"
else
    mkdir -p ~/.vim/pack/plugins/start/
    git clone https://github.com/42Paris/42header.git ~/.vim/pack/plugins/start/42header
    echo -e "${GREEN}✓ 42header installed${NC}"
fi

# Configure vimrc if not already done
if grep -q "g:user42" "$HOME/.vimrc" 2>/dev/null; then
    echo -e "${GREEN}✓ .vimrc already configured${NC}"
else
    echo -e "${YELLOW}Configuring .vimrc...${NC}"
    echo 'let g:user42 = "Arash Javan Mojarad"' >> ~/.vimrc
    echo 'let g:mail42 = "ajavan-m@student.42vienna.com"' >> ~/.vimrc
    echo -e "${GREEN}✓ .vimrc configured${NC}"
fi

echo ""
echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}Setup Complete!${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""
echo -e "${YELLOW}Next steps:${NC}"
echo "1. Reload your shell: source $SHELL_RC"
echo "2. Test norminette: norminette <file.c>"
echo "3. Test mini-moulinette: cd C03 && mini C03"
echo "4. Use Vim header: vim <file.c> then :Stdheader"
echo ""
echo -e "${GREEN}Happy coding! 🚀${NC}"
