#!/bin/sh
# Test script for ft_list_merge

gcc -Wall -Wextra -Werror main.c ft_list_merge.c ft_create_elem.c -o test_ex13
./test_ex13
rm -f test_ex13
