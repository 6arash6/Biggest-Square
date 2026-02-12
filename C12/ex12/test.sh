#!/bin/sh
# Test script for ft_list_remove_if

gcc -Wall -Wextra -Werror main.c ft_list_remove_if.c ft_create_elem.c -o test_ex12
./test_ex12
rm -f test_ex12
