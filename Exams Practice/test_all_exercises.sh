#!/bin/bash

# **************************************************************************** #
#                                                                              #
#    test_all_exercises.sh - Quick test script for all new exercises          #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
RESET='\033[0m'

echo ""
echo -e "${BLUE}========================================${RESET}"
echo -e "${BLUE}  Testing All New Exam Exercises       ${RESET}"
echo -e "${BLUE}========================================${RESET}"
echo ""

# Change to the Exam01 directory
cd "$(dirname "$0")/Exam01" 2>/dev/null || {
    echo -e "${RED}Error: Could not find Exam01 directory${RESET}"
    exit 1
}

# Array of exercises
exercises=(
    "2-aff_even"
    "3-repeat_alpha"
    "4-fizzbuzz"
    "5-aff_odd"
    "6-alpha_mirror"
    "7-search_and_replace"
)

passed=0
failed=0

# Test each exercise
for ex in "${exercises[@]}"; do
    echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
    echo -e "${BLUE}Testing: $ex${RESET}"
    echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
    echo ""
    
    # Compile
    gcc -Wall -Wextra -Werror "$ex"/test_*.c -o "$ex"/test 2>&1
    
    if [ $? -eq 0 ]; then
        # Run test
        ./"$ex"/test
        
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}✓ $ex passed${RESET}"
            ((passed++))
        else
            echo -e "${RED}✗ $ex failed at runtime${RESET}"
            ((failed++))
        fi
        
        # Clean up
        rm "$ex"/test
    else
        echo -e "${RED}✗ $ex compilation failed${RESET}"
        ((failed++))
    fi
    
    echo ""
done

# Summary
echo -e "${YELLOW}========================================${RESET}"
echo -e "${BLUE}  Test Summary                         ${RESET}"
echo -e "${YELLOW}========================================${RESET}"
echo ""
echo -e "${GREEN}Passed: $passed${RESET}"
echo -e "${RED}Failed: $failed${RESET}"
echo -e "Total:  $((passed + failed))"
echo ""

if [ $failed -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed successfully!${RESET}"
else
    echo -e "${RED}⚠️  Some tests failed. Check output above.${RESET}"
fi

echo ""
