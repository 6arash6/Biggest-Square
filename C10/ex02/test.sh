#!/bin/sh
# Test script for ft_list_last

gcc -Wall -Wextra -Werror main.c ft_list_last.c ft_list_push_front.c -o test_ex02
./test_ex02
rm -f test_ex02
