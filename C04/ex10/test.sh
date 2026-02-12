#!/bin/sh
# Test script for ft_strcapitalize

gcc -Wall -Wextra -Werror main.c ft_strcapitalize.c -o test_ex10
./test_ex10
rm -f test_ex10
