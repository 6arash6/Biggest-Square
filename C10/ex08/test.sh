#!/bin/sh
# Test script for ft_list_merge

gcc -Wall -Wextra -Werror main.c ft_list_merge.c ft_list_push_back.c -o test_ex08
./test_ex08
rm -f test_ex08
