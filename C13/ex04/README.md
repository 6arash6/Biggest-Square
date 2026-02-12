# ex04: btree_insert_data

## Objective
Insert an item into a binary tree using a comparison function.

## Function Prototype
```c
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
```

## Beginner Explanation
- Use cmpf to decide left or right.
- Recursively insert item.

## Example
```c
btree_insert_data(&root, &value, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
