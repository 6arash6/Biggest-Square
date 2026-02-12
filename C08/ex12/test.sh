#!/bin/sh
# Test script for ft_strncpy

gcc -Wall -Wextra -Werror main.c ft_strncpy.c -o test_ex12
./test_ex12
rm -f test_ex12
