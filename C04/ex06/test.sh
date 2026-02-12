#!/bin/sh
# Test script for ft_str_is_uppercase

gcc -Wall -Wextra -Werror main.c ft_str_is_uppercase.c -o test_ex06
./test_ex06
rm -f test_ex06
