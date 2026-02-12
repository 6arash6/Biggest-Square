#!/bin/sh
# Test script for ft_list_push_front

gcc -Wall -Wextra -Werror main.c ft_list_push_front.c -o test_ex00
./test_ex00
rm -f test_ex00
