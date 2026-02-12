#!/bin/sh
# Test script for ft_sorted_list_merge

gcc -Wall -Wextra -Werror main.c ft_sorted_list_merge.c ft_create_elem.c -o test_ex17
./test_ex17
rm -f test_ex17
