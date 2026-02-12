# ex08: ft_list_merge

## Objective
Write a function that merges two linked lists.

## Function Prototype
```c
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
```

## Beginner Explanation
- Add begin_list2 to the end of begin_list1.

## Example
```c
ft_list_merge(&head1, head2);
```

## Steps
1. If begin_list1 is empty, set to begin_list2.
2. Else, add begin_list2 to end.

## Manual Testing
Use the provided main.c to test different cases.
