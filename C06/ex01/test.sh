#!/bin/sh
# Test script for ft_print_params

gcc -Wall -Wextra -Werror ft_print_params.c -o test_ex01
./test_ex01 hello world
rm -f test_ex01
