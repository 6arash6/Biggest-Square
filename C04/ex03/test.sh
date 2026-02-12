#!/bin/sh
# Test script for ft_str_is_alpha

gcc -Wall -Wextra -Werror main.c ft_str_is_alpha.c -o test_ex03
./test_ex03
rm -f test_ex03
