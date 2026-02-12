#!/bin/sh
# Test script for ft_list_foreach_if

gcc -Wall -Wextra -Werror main.c ft_list_foreach_if.c ft_create_elem.c -o test_ex10
./test_ex10
rm -f test_ex10
