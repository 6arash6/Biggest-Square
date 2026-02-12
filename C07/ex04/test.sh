#!/bin/sh
# Test script for ft_max

gcc -Wall -Wextra -Werror main.c ft_max.c -o test_ex04
./test_ex04
rm -f test_ex04
