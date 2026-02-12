#!/bin/sh
# Test script for ft_sorted_list_insert

gcc -Wall -Wextra -Werror main.c ft_sorted_list_insert.c ft_create_elem.c -o test_ex16
./test_ex16
rm -f test_ex16
