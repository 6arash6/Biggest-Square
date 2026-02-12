#!/bin/sh
# Test script for ft_list_clear

gcc -Wall -Wextra -Werror main.c ft_list_clear.c ft_create_elem.c -o test_ex06
./test_ex06
rm -f test_ex06
