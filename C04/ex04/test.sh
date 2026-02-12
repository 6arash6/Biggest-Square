#!/bin/sh
# Test script for ft_str_is_numeric

gcc -Wall -Wextra -Werror main.c ft_str_is_numeric.c -o test_ex04
./test_ex04
rm -f test_ex04
