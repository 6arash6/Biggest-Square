#!/bin/sh
# Test script for ft_ten_queens_puzzle

gcc -Wall -Wextra -Werror main.c ft_ten_queens_puzzle.c -o test_ex08
./test_ex08
rm -f test_ex08
