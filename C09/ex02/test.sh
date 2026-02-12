#!/bin/sh
# Test script for ft_putnbr

gcc -Wall -Wextra -Werror main.c ft_putnbr.c ft_putchar.c -o test_ex02
./test_ex02
rm -f test_ex02
