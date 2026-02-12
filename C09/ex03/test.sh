#!/bin/sh
# Test script for ft_atoi

gcc -Wall -Wextra -Werror main.c ft_atoi.c -o test_ex03
./test_ex03
rm -f test_ex03
