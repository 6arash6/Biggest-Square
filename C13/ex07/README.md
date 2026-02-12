# ex07: btree_apply_by_level

## Objective
Apply a function to each item in a binary tree by level.

## Function Prototype
```c
void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
```

## Beginner Explanation
- Traverse the tree level by level (BFS).
- Call applyf for each item, passing current level and if it's the first element at that level.

## Example
```c
btree_apply_by_level(root, applyf);
```

## Manual Testing
Use the provided main.c to test different cases.
