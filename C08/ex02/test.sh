#!/bin/sh
# Test script for ft_strsplit

gcc -Wall -Wextra -Werror main.c ft_strsplit.c -o test_ex02
./test_ex02
rm -f test_ex02
