# Sort Linked List (sort_list)

## Problem
Write a function that sorts a singly linked list in ascending order.

## Example
Input: 3 -> 1 -> 2
Output: 1 -> 2 -> 3

## Key Concepts
- Linked list manipulation
- Sorting algorithms (bubble sort)

## Sample Solution
```c
#include <stdlib.h>

typedef struct s_list { int data; struct s_list *next; } t_list;

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *cur;
    int tmp;
    int sorted;
    if (!lst) return NULL;
    sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        cur = lst;
        while (cur->next)
        {
            if (!cmp(cur->data, cur->next->data))
            {
                tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                sorted = 0;
            }
            cur = cur->next;
        }
    }
    return lst;
}

int ascending(int a, int b) { return (a <= b); }
```

## Edge Cases
- Empty list
- List of size 1

---

*Try with different lists for practice!*
