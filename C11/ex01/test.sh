#!/bin/sh
# Test script for ft_map

gcc -Wall -Wextra -Werror main.c ft_map.c -o test_ex01
./test_ex01
rm -f test_ex01
