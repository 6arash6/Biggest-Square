#!/bin/sh
# Test script for ft_str_to_lower

gcc -Wall -Wextra -Werror main.c ft_str_to_lower.c -o test_ex09
./test_ex09
rm -f test_ex09
