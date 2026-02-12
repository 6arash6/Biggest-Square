# Reverse Range Array Allocation (ft_rrange)

## Problem
Write a function that allocates (malloc) and returns an array of integers from end to start (inclusive).

## Example
Input: 1, 3
Output: [3, 2, 1]

## Key Concepts
- Dynamic memory allocation
- Array construction

## Sample Solution
```c
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int len = (start > end) ? (start - end + 1) : (end - start + 1);
    int *arr = malloc(len * sizeof(int));
    int i = 0;
    if (!arr) return NULL;
    if (start <= end)
        while (end >= start) arr[i++] = end--;
    else
        while (end <= start) arr[i++] = end++;
    return arr;
}
```

## Edge Cases
- start == end (array of one element)
- start > end

---

*Try with different start/end values!*
