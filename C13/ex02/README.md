# ex02: btree_apply_infix

## Objective
Apply a function to each item in a binary tree (infix order).

## Function Prototype
```c
void btree_apply_infix(t_btree *root, void (*applyf)(void *));
```

## Beginner Explanation
- Visit left, then root, then right.
- Call applyf for each item.

## Example
```c
btree_apply_infix(root, print);
```

## Manual Testing
Use the provided main.c to test different cases.
