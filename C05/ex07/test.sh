#!/bin/sh
# Test script for ft_find_next_prime

gcc -Wall -Wextra -Werror main.c ft_find_next_prime.c ft_is_prime.c -o test_ex07
./test_ex07
rm -f test_ex07
