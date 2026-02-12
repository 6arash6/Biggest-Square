#!/bin/sh
# Test script for ft_sort_int_tab

gcc -Wall -Wextra -Werror main.c ft_sort_int_tab.c -o test_ex06
./test_ex06
rm -f test_ex06
