#!/bin/sh
# Test script for ft_putstr

gcc -Wall -Wextra -Werror main.c ft_putstr.c -o test_ex01
./test_ex01
rm -f test_ex01
