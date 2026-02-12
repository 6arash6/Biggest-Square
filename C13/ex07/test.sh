#!/bin/sh
# Test script for btree_apply_by_level

gcc -Wall -Wextra -Werror main.c btree_apply_by_level.c btree_create_node.c -o test_ex07
./test_ex07
rm -f test_ex07
