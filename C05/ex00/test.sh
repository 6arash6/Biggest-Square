#!/bin/sh
# Test script for ft_iterative_factorial

gcc -Wall -Wextra -Werror main.c ft_iterative_factorial.c -o test_ex00
./test_ex00
rm -f test_ex00
