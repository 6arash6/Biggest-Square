#!/bin/sh
# Test script for ft_min

gcc -Wall -Wextra -Werror main.c ft_min.c -o test_ex05
./test_ex05
rm -f test_ex05
