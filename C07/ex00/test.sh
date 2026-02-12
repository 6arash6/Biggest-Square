#!/bin/sh
# Test script for ft_strdup

gcc -Wall -Wextra -Werror main.c ft_strdup.c -o test_ex00
./test_ex00
rm -f test_ex00
