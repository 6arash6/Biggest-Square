#!/bin/sh
# Test script for btree_create_node

gcc -Wall -Wextra -Werror main.c btree_create_node.c -o test_ex00
./test_ex00
rm -f test_ex00
