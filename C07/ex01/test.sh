#!/bin/sh
# Test script for ft_range

gcc -Wall -Wextra -Werror main.c ft_range.c -o test_ex01
./test_ex01
rm -f test_ex01
