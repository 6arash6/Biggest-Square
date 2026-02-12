#!/bin/sh
# Test script for ft_list_clear

gcc -Wall -Wextra -Werror main.c ft_list_clear.c ft_list_push_back.c -o test_ex04
./test_ex04
rm -f test_ex04
