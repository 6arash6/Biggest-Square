#!/bin/sh
# Test script for ft_print_rev_params

gcc -Wall -Wextra -Werror ft_print_rev_params.c -o test_ex02
./test_ex02 hello world
rm -f test_ex02
