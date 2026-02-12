#!/bin/sh
# Test script for btree_apply_suffix

gcc -Wall -Wextra -Werror main.c btree_apply_suffix.c btree_create_node.c -o test_ex03
./test_ex03
rm -f test_ex03
