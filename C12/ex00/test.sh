#!/bin/sh
# Test script for ft_create_elem

gcc -Wall -Wextra -Werror main.c ft_create_elem.c -o test_ex00
./test_ex00
rm -f test_ex00
