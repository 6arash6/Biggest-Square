#!/bin/sh
# Test script for ft_strncmp

gcc -Wall -Wextra -Werror main.c ft_strncmp.c -o test_ex07
./test_ex07
rm -f test_ex07
