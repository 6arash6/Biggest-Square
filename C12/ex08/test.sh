#!/bin/sh
# Test script for ft_list_reverse

gcc -Wall -Wextra -Werror main.c ft_list_reverse.c ft_create_elem.c -o test_ex08
./test_ex08
rm -f test_ex08
