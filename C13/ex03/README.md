# ex03: btree_apply_suffix

## Objective
Apply a function to each item in a binary tree (suffix/postfix order).

## Function Prototype
```c
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));
```

## Beginner Explanation
- Visit left, then right, then root.
- Call applyf for each item.

## Example
```c
btree_apply_suffix(root, print);
```

## Manual Testing
Use the provided main.c to test different cases.
