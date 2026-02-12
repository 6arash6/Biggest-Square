#!/bin/sh
# Test script for ft_strjoin

gcc -Wall -Wextra -Werror main.c ft_strjoin.c -o test_ex01
./test_ex01
rm -f test_ex01
