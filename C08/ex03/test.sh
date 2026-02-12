#!/bin/sh
# Test script for ft_strtrim

gcc -Wall -Wextra -Werror main.c ft_strtrim.c -o test_ex03
./test_ex03
rm -f test_ex03
