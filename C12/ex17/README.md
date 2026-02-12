# ex17: ft_sorted_list_merge

## Objective
Merge two sorted linked lists.

## Function Prototype
```c
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)(void *, void *));
```

## Beginner Explanation
- Merge lists while keeping order using cmp.

## Example
```c
ft_sorted_list_merge(&head1, head2, cmp);
```

## Manual Testing
Use the provided main.c to test different cases.
