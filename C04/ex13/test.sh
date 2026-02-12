#!/bin/sh
# Test script for ft_str_non_printable

gcc -Wall -Wextra -Werror main.c ft_str_non_printable.c -o test_ex13
./test_ex13
rm -f test_ex13
