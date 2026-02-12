#!/bin/sh
# Test script for ft_list_push_back

gcc -Wall -Wextra -Werror main.c ft_list_push_back.c -o test_ex03
./test_ex03
rm -f test_ex03
