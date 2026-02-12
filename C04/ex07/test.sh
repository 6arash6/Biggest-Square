#!/bin/sh
# Test script for ft_str_is_printable

gcc -Wall -Wextra -Werror main.c ft_str_is_printable.c -o test_ex07
./test_ex07
rm -f test_ex07
