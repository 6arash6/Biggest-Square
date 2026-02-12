#!/bin/sh
# Test script for ft_split

gcc -Wall -Wextra -Werror main.c ft_split.c -o test_ex05
./test_ex05
rm -f test_ex05
