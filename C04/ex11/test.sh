#!/bin/sh
# Test script for ft_strlcpy

gcc -Wall -Wextra -Werror main.c ft_strlcpy.c -o test_ex11
./test_ex11
rm -f test_ex11
