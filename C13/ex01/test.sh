#!/bin/sh
# Test script for btree_apply_prefix

gcc -Wall -Wextra -Werror main.c btree_apply_prefix.c btree_create_node.c -o test_ex01
./test_ex01
rm -f test_ex01
