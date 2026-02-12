#!/bin/sh
# Test script for ft_print_program_name

gcc -Wall -Wextra -Werror ft_print_program_name.c -o test_ex00
./test_ex00
rm -f test_ex00
