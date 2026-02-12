#!/bin/sh
# Test script for ft_strncat

gcc -Wall -Wextra -Werror main.c ft_strncat.c -o test_ex11
./test_ex11
rm -f test_ex11
