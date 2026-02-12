# ex05: btree_search_item

## Objective
Search for an item in a binary tree using a comparison function.

## Function Prototype
```c
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
```

## Beginner Explanation
- Use cmpf to compare data_ref with node item.
- Recursively search left or right.
- Return pointer to item if found, else NULL.

## Example
```c
void *found = btree_search_item(root, &value, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
