#!/bin/sh
# Test script for ft_advanced_sort_string_tab

gcc -Wall -Wextra -Werror main.c ft_advanced_sort_string_tab.c -o test_ex07
./test_ex07
rm -f test_ex07
