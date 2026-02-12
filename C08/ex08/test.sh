#!/bin/sh
# Test script for ft_strstr

gcc -Wall -Wextra -Werror main.c ft_strstr.c -o test_ex08
./test_ex08
rm -f test_ex08
