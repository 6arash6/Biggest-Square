#!/bin/bash

# **************************************************************************** #
#                                                                              #
#    Quick Practice Script - Most Common Exam Exercises                       #
#    Practice these tonight for tomorrow's exam!                              #
#                                                                              #
# **************************************************************************** #

echo "
╔══════════════════════════════════════════════════════════════╗
║                                                              ║
║        🔥 TONIGHT'S FOCUSED PRACTICE - 2 HOURS MAX 🔥        ║
║                                                              ║
║      Based on your 50% pass - focus on high-frequency       ║
║      exercises that will secure you another passing score!  ║
║                                                              ║
╚══════════════════════════════════════════════════════════════╝
"

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
RESET='\033[0m'

echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo -e "${BLUE}PRIORITY 1: MUST MASTER (30 minutes)${RESET}"
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo ""
echo "These appear in EVERY exam. Do them in VIM, from memory:"
echo ""
echo -e "${GREEN}1.${RESET} ft_strlen - Count string length"
echo -e "${GREEN}2.${RESET} fizzbuzz - The classic 1-100 problem"
echo -e "${GREEN}3.${RESET} aff_last_param - Print last argument"
echo -e "${GREEN}4.${RESET} first_word - Print first word of string"
echo ""
echo "⏱️  Set 5-min timer per exercise. GO!"
echo ""
read -p "Press ENTER when you've practiced these 4..."

echo ""
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo -e "${BLUE}PRIORITY 2: HIGH FREQUENCY (45 minutes)${RESET}"
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo ""
echo "Very common in Level 1-2 exams:"
echo ""
echo -e "${GREEN}5.${RESET} ft_atoi - String to integer ⭐ CRUCIAL!"
echo -e "${GREEN}6.${RESET} rot_13 - Character rotation (a→n, n→a)"
echo -e "${GREEN}7.${RESET} rev_print - Print string backwards"
echo -e "${GREEN}8.${RESET} ft_strcmp - Compare two strings"
echo ""
echo "⏱️  10 minutes each. Code + compile + test."
echo ""
read -p "Press ENTER when you've practiced these..."

echo ""
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo -e "${BLUE}PRIORITY 3: IF C05 APPEARS (30 minutes)${RESET}"
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo ""
echo "Recursion basics (Level 3):"
echo ""
echo -e "${GREEN}9.${RESET} ft_recursive_factorial - n! = n × (n-1)!"
echo -e "${GREEN}10.${RESET} ft_recursive_power - n^p = n × n^(p-1)"
echo ""
echo "💡 TIP: If stuck, write iterative version first!"
echo ""
echo "📖 Study the cheatsheet: C05_CHEATSHEET.c"
echo ""
read -p "Press ENTER when ready for final review..."

echo ""
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo -e "${BLUE}PRIORITY 4: QUICK WINS (15 minutes)${RESET}"
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo ""
echo "Easy points if they appear:"
echo ""
echo -e "${GREEN}11.${RESET} ft_putstr - Print string with write()"
echo -e "${GREEN}12.${RESET} ft_swap - Swap two integers"
echo ""
read -p "Press ENTER for final checklist..."

echo ""
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo -e "${GREEN}✅ EXAM READINESS CHECKLIST${RESET}"
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo ""
echo "Can you do these FROM MEMORY (no looking)?"
echo ""
echo "[ ] Write ft_strlen in 2 minutes"
echo "[ ] Write ft_atoi in 10 minutes"
echo "[ ] Handle argc/argv correctly"
echo "[ ] Always print newline"
echo "[ ] Remember to use write(), not printf"
echo "[ ] Compile with -Wall -Wextra -Werror"
echo ""
echo -e "${BLUE}If you checked all boxes → You're ready! 🎯${RESET}"
echo ""

echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo -e "${RED}🛑 STOP STUDYING BY 10 PM!${RESET}"
echo -e "${YELLOW}═══════════════════════════════════════════════════════${RESET}"
echo ""
echo "Sleep is MORE important than cramming!"
echo ""
echo "Tomorrow's strategy:"
echo "  1. Start with easiest exercises"
echo "  2. Get 50%+ before attempting hard ones"
echo "  3. Stay calm and read subjects carefully"
echo ""
echo -e "${GREEN}You passed once, you'll pass again! 💪${RESET}"
echo ""
echo "═══════════════════════════════════════════════════════"
echo ""
echo "Quick references created:"
echo "  📖 EXAM_PREP_TOMORROW.md - Complete study guide"
echo "  📖 C05_CHEATSHEET.c - Recursion patterns"
echo ""
echo "Good luck tomorrow! 🍀"
echo ""
