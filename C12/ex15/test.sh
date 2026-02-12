#!/bin/sh
# Test script for ft_list_reverse_fun

gcc -Wall -Wextra -Werror main.c ft_list_reverse_fun.c ft_create_elem.c -o test_ex15
./test_ex15
rm -f test_ex15
