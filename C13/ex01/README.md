# ex01: btree_apply_prefix

## Objective
Apply a function to each item in a binary tree (prefix order).

## Function Prototype
```c
void btree_apply_prefix(t_btree *root, void (*applyf)(void *));
```

## Beginner Explanation
- Visit root, then left, then right.
- Call applyf for each item.

## Example
```c
btree_apply_prefix(root, print);
```

## Manual Testing
Use the provided main.c to test different cases.
