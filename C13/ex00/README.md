# ex00: btree_create_node

## Objective
Create a new binary tree node and assign item.

## Function Prototype
```c
t_btree *btree_create_node(void *item);
```

## Beginner Explanation
- Allocate memory for a new node.
- Set its item to the argument.
- Set left and right to NULL.

## Example
```c
t_btree *node = btree_create_node(&value);
```

## Manual Testing
Use the provided main.c to test different cases.
