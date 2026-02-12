#!/bin/sh
# Test script for ft_list_size

gcc -Wall -Wextra -Werror main.c ft_list_size.c ft_create_elem.c -o test_ex02
./test_ex02
rm -f test_ex02
