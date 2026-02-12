#!/bin/sh
# Test script for ft_list_remove_if

gcc -Wall -Wextra -Werror main.c ft_list_remove_if.c ft_list_push_back.c -o test_ex07
./test_ex07
rm -f test_ex07
