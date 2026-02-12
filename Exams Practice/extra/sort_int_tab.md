# Sort Integer Array (sort_int_tab)

## Problem
Write a function that sorts an array of integers in ascending order (in-place).

## Example
Input: [3, 1, 2]
Output: [1, 2, 3]

## Key Concepts
- Array manipulation
- Sorting algorithms (bubble sort)

## Sample Solution
```c
void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i, j;
    int tmp;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - 1 - i; j++)
            if (tab[j] > tab[j + 1])
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
}
```

## Edge Cases
- Empty array
- Array of size 1

---

*Try with different arrays for practice!*
