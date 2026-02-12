#!/bin/sh
# Test script for ft_any

gcc -Wall -Wextra -Werror main.c ft_any.c -o test_ex02
./test_ex02
rm -f test_ex02
