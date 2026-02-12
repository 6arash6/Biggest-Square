#!/bin/sh
# Test script for ft_strcpy

gcc -Wall -Wextra -Werror main.c ft_strcpy.c -o test_ex13
./test_ex13
rm -f test_ex13
