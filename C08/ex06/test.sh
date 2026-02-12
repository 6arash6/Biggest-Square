#!/bin/sh
# Test script for ft_strcmp

gcc -Wall -Wextra -Werror main.c ft_strcmp.c -o test_ex06
./test_ex06
rm -f test_ex06
