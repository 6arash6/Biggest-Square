#!/bin/sh
# Test script for ft_is_prime

gcc -Wall -Wextra -Werror main.c ft_is_prime.c -o test_ex06
./test_ex06
rm -f test_ex06
