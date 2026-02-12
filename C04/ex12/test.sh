#!/bin/sh
# Test script for ft_strlcat

gcc -Wall -Wextra -Werror main.c ft_strlcat.c -o test_ex12
./test_ex12
rm -f test_ex12
