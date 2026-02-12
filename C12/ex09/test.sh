#!/bin/sh
# Test script for ft_list_foreach

gcc -Wall -Wextra -Werror main.c ft_list_foreach.c ft_create_elem.c -o test_ex09
./test_ex09
rm -f test_ex09
