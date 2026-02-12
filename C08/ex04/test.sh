#!/bin/sh
# Test script for ft_strrev

gcc -Wall -Wextra -Werror main.c ft_strrev.c -o test_ex04
./test_ex04
rm -f test_ex04
