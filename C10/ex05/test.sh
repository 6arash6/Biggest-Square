#!/bin/sh
# Test script for ft_list_at

gcc -Wall -Wextra -Werror main.c ft_list_at.c ft_list_push_back.c -o test_ex05
./test_ex05
rm -f test_ex05
