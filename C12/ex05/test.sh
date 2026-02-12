#!/bin/sh
# Test script for ft_list_push_strs

gcc -Wall -Wextra -Werror main.c ft_list_push_strs.c ft_create_elem.c -o test_ex05
./test_ex05
rm -f test_ex05
