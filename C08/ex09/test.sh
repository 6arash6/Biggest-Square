#!/bin/sh
# Test script for ft_strlcpy

gcc -Wall -Wextra -Werror main.c ft_strlcpy.c -o test_ex09
./test_ex09
rm -f test_ex09
