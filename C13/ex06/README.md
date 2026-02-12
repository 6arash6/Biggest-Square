# ex06: btree_level_count

## Objective
Count the number of levels in a binary tree.

## Function Prototype
```c
int btree_level_count(t_btree *root);
```

## Beginner Explanation
- Recursively count levels in left and right subtrees.
- Return the maximum + 1.

## Example
```c
int levels = btree_level_count(root);
```

## Manual Testing
Use the provided main.c to test different cases.
