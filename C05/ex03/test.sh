#!/bin/sh
# Test script for ft_recursive_power

gcc -Wall -Wextra -Werror main.c ft_recursive_power.c -o test_ex03
./test_ex03
rm -f test_ex03
