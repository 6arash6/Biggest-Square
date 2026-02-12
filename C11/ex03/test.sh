#!/bin/sh
# Test script for ft_count_if

gcc -Wall -Wextra -Werror main.c ft_count_if.c -o test_ex03
./test_ex03
rm -f test_ex03
