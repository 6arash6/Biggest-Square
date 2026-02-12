#!/bin/sh
# Test script for btree_apply_infix

gcc -Wall -Wextra -Werror main.c btree_apply_infix.c btree_create_node.c -o test_ex02
./test_ex02
rm -f test_ex02
