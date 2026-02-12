#!/bin/sh
# Test script for ft_itoa

gcc -Wall -Wextra -Werror main.c ft_itoa.c -o test_ex04
./test_ex04
rm -f test_ex04
