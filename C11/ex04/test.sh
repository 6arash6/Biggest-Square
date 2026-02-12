#!/bin/sh
# Test script for ft_is_sort

gcc -Wall -Wextra -Werror main.c ft_is_sort.c -o test_ex04
./test_ex04
rm -f test_ex04
