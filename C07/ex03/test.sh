#!/bin/sh
# Test script for ft_sum

gcc -Wall -Wextra -Werror main.c ft_sum.c -o test_ex03
./test_ex03
rm -f test_ex03
