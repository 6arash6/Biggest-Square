#!/bin/sh
# Test script for btree_level_count

gcc -Wall -Wextra -Werror main.c btree_level_count.c btree_create_node.c -o test_ex06
./test_ex06
rm -f test_ex06
