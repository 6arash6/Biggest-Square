#!/bin/sh
# Test script for ft_list_push_front

gcc -Wall -Wextra -Werror main.c ft_list_push_front.c ft_create_elem.c -o test_ex01
./test_ex01
rm -f test_ex01
