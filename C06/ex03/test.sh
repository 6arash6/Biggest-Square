#!/bin/sh
# Test script for ft_params_sum

gcc -Wall -Wextra -Werror ft_params_sum.c -o test_ex03
./test_ex03 hello world
rm -f test_ex03
