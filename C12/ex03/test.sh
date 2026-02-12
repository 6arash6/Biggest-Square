#!/bin/sh
# Test script for ft_list_last

gcc -Wall -Wextra -Werror main.c ft_list_last.c ft_create_elem.c -o test_ex03
./test_ex03
rm -f test_ex03
