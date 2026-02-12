#!/bin/sh
# Test script for ft_foreach

gcc -Wall -Wextra -Werror main.c ft_foreach.c -o test_ex00
./test_ex00
rm -f test_ex00
