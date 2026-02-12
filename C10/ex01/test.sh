#!/bin/sh
# Test script for ft_list_size

gcc -Wall -Wextra -Werror main.c ft_list_size.c ft_list_push_front.c -o test_ex01
./test_ex01
rm -f test_ex01
