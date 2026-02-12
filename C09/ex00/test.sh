#!/bin/sh
# Test script for ft_putchar

gcc -Wall -Wextra -Werror main.c ft_putchar.c -o test_ex00
./test_ex00
rm -f test_ex00
