#!/bin/sh
# Test script for ft_strcat

gcc -Wall -Wextra -Werror main.c ft_strcat.c -o test_ex05
./test_ex05
rm -f test_ex05
