#!/bin/sh
# Test script for ft_list_find

gcc -Wall -Wextra -Werror main.c ft_list_find.c ft_create_elem.c -o test_ex11
./test_ex11
rm -f test_ex11
