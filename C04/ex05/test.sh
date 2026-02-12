#!/bin/sh
# Test script for ft_str_is_lowercase

gcc -Wall -Wextra -Werror main.c ft_str_is_lowercase.c -o test_ex05
./test_ex05
rm -f test_ex05
