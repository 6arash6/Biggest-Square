#!/bin/sh
# Test script for ft_sqrt

gcc -Wall -Wextra -Werror main.c ft_sqrt.c -o test_ex05
./test_ex05
rm -f test_ex05
