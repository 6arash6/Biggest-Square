#!/bin/sh
# Test script for btree_search_item

gcc -Wall -Wextra -Werror main.c btree_search_item.c btree_create_node.c btree_insert_data.c -o test_ex05
./test_ex05
rm -f test_ex05
