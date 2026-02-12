#!/bin/sh
# Test script for btree_insert_data

gcc -Wall -Wextra -Werror main.c btree_insert_data.c btree_create_node.c btree_apply_prefix.c -o test_ex04
./test_ex04
rm -f test_ex04
