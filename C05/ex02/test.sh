#!/bin/sh
# Test script for ft_iterative_power

gcc -Wall -Wextra -Werror main.c ft_iterative_power.c -o test_ex02
./test_ex02
rm -f test_ex02
