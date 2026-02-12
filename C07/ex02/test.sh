#!/bin/sh
# Test script for ft_ultimate_range

gcc -Wall -Wextra -Werror main.c ft_ultimate_range.c -o test_ex02
./test_ex02
rm -f test_ex02
