#!/bin/sh
# Test script for ft_recursive_factorial

gcc -Wall -Wextra -Werror main.c ft_recursive_factorial.c -o test_ex01
./test_ex01
rm -f test_ex01
