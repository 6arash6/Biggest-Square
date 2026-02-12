#!/bin/sh
# Test script for ft_create_array

gcc -Wall -Wextra -Werror main.c ft_create_array.c -o test_ex00
./test_ex00
rm -f test_ex00
