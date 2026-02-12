#!/bin/sh
# Test script for ft_fibonacci

gcc -Wall -Wextra -Werror main.c ft_fibonacci.c -o test_ex04
./test_ex04
rm -f test_ex04
