#!/bin/sh
# Test script for ft_strlcat

gcc -Wall -Wextra -Werror main.c ft_strlcat.c -o test_ex10
./test_ex10
rm -f test_ex10
