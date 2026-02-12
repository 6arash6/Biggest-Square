#!/bin/sh
# Test script for ft_list_sort

gcc -Wall -Wextra -Werror main.c ft_list_sort.c ft_create_elem.c -o test_ex14
./test_ex14
rm -f test_ex14
