#!/bin/sh
# Test script for ft_list_sort

gcc -Wall -Wextra -Werror main.c ft_list_sort.c ft_list_push_back.c -o test_ex09
./test_ex09
rm -f test_ex09
