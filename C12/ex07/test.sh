#!/bin/sh
# Test script for ft_list_at

gcc -Wall -Wextra -Werror main.c ft_list_at.c ft_create_elem.c -o test_ex07
./test_ex07
rm -f test_ex07
