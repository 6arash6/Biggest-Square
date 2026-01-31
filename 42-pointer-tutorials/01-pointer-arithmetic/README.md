# 01-pointer-arithmetic: Moving Pointers in Memory

## Learning Objectives
By the end of this section, you should be able to:
- Increment and decrement pointers
- Traverse arrays using pointer arithmetic
- Calculate pointer differences
- Understand how pointer arithmetic relates to type sizes

## Key Concepts

### Pointer Arithmetic Basics
When you add or subtract from a pointer, it doesn't move by 1 byte - it moves by the size of the type!

```c
int arr[5];
int *ptr = arr;

ptr++;  // Moves forward by sizeof(int) bytes (usually 4)
ptr--;  // Moves backward by sizeof(int) bytes
```

### Why This Matters
```c
char *c_ptr;  // Points to char (1 byte)
int *i_ptr;   // Points to int (4 bytes)

c_ptr++;  // Moves 1 byte forward
i_ptr++;  // Moves 4 bytes forward (one int)
```

The compiler knows the type, so it does the math for you!

### Adding Numbers to Pointers
```c
int arr[10];
int *ptr = arr;

ptr + 3;  // Points to arr[3]
ptr + 5;  // Points to arr[5]
```

## Files in This Section

### 00-increment-decrement.c
Shows basic pointer movement:
- `ptr++` - move to next element
- `ptr--` - move to previous element
- Watch the pointer "walk" through the array

**Python Tutor Focus:** 
- See where `ptr` points after each operation
- Notice it jumps to the next array element

### 01-array-traversal.c
Practical example: summing array elements
- Uses pointer instead of array indexing
- Shows how `*ptr` gets current value
- Shows how `ptr++` moves to next

**Python Tutor Focus:**
- Watch `sum` accumulate
- See `ptr` move through each element
- Compare to using `arr[i]`

### 02-pointer-difference.c
Demonstrates pointer subtraction:
- `end - start` gives number of elements between
- Useful for calculating sizes
- Always gives difference in elements, not bytes

**Python Tutor Focus:**
- See the difference calculation
- Understand why `diff` is 4 (not 16 bytes)

## Using with Python Tutor

1. Copy code to https://pythontutor.com/c.html
2. Step through slowly
3. Watch the pointer variable - it shows as an arrow
4. Notice how the arrow moves through the array

### Key Things to Observe:
- Pointer value changes (the address)
- What the pointer points to (follows the arrow)
- The actual values in the array don't change (unless you modify them)

## Important Rules

### What You CAN Do:
✅ Add/subtract integers to/from pointers
```c
ptr + 3
ptr - 2
ptr++
ptr--
```

✅ Subtract two pointers (same array)
```c
end - start  // Gives distance in elements
```

✅ Compare pointers
```c
if (ptr1 < ptr2)
if (ptr == &arr[0])
```

### What You CANNOT Do:
❌ Add two pointers
```c
ptr1 + ptr2  // Makes no sense!
```

❌ Multiply or divide pointers
```c
ptr * 2  // Not allowed!
ptr / 2  // Not allowed!
```

## Equivalences to Remember

These are the SAME:
```c
arr[i]      <==>  *(arr + i)
&arr[i]     <==>  arr + i
ptr[i]      <==>  *(ptr + i)
```

Example:
```c
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;

arr[2]      // 30
*(arr + 2)  // 30 (same thing!)
ptr[2]      // 30
*(ptr + 2)  // 30 (same thing!)
```

## Practice Exercises

1. **Pointer Walking**
   - Create an array of 10 integers
   - Use a pointer to visit each element
   - Without using [], access and modify each element

2. **Find Element**
   - Create an array with values: {5, 10, 15, 20, 25}
   - Use pointer arithmetic to find value 15
   - Calculate its index using pointer difference

3. **Reverse Traversal**
   - Start a pointer at the end of an array
   - Use `ptr--` to go backwards
   - Print elements in reverse order

4. **Calculate Length**
   - Given start and end pointers of an array
   - Calculate the array length using subtraction

## Common Mistakes to Avoid

❌ **Going out of bounds:**
```c
int arr[5];
int *ptr = arr;
ptr = ptr + 10;  // Dangerous! Outside array
```

❌ **Comparing unrelated pointers:**
```c
int arr1[5];
int arr2[5];
if (arr1 < arr2)  // Meaningless comparison
```

❌ **Forgetting to dereference:**
```c
int arr[3] = {1, 2, 3};
int *ptr = arr;
int sum = ptr;  // ERROR! ptr is address, not value
```

✅ **Correct:**
```c
int sum = *ptr;  // OK! Dereferences to get value
```

## Next Steps
Move on to **02-pointers-and-arrays** to learn:
- How arrays and pointers are related
- Array notation vs pointer notation
- String manipulation with pointers
