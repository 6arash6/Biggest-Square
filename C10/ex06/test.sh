#!/bin/sh
# Test script for ft_list_reverse

gcc -Wall -Wextra -Werror main.c ft_list_reverse.c ft_list_push_back.c -o test_ex06
./test_ex06
rm -f test_ex06
