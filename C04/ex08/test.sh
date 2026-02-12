#!/bin/sh
# Test script for ft_str_to_upper

gcc -Wall -Wextra -Werror main.c ft_str_to_upper.c -o test_ex08
./test_ex08
rm -f test_ex08
