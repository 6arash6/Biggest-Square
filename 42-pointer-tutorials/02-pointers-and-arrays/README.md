# 02-pointers-and-arrays: The Deep Connection

## Learning Objectives
By the end of this section, you should be able to:
- Understand that array names are pointers
- Use both array and pointer notation interchangeably
- Manipulate strings using pointers
- Understand the equivalence between `arr[i]` and `*(arr + i)`

## Key Concepts

### Arrays ARE Pointers (mostly)
When you declare an array, its name is a pointer to the first element:

```c
int arr[5];
// arr is equivalent to &arr[0]
// arr is a pointer to arr[0]
```

### The Big Secret
```c
arr[i]  is just syntactic sugar for  *(arr + i)
```

Yes, really! When you write `arr[3]`, the compiler converts it to `*(arr + 3)`.

### Array vs Pointer - Key Difference
```c
int arr[5];     // Array - fixed size, can't be reassigned
int *ptr;       // Pointer - can point anywhere, can be reassigned

ptr = arr;      // OK! ptr now points to arr
arr = ptr;      // ERROR! Can't reassign array name
```

## Files in This Section

### 00-array-as-pointer.c
Demonstrates the fundamental truth:
- Array name is a pointer
- Can assign array to pointer
- Both point to the same memory

**Python Tutor Focus:**
- See that `arr` and `ptr` point to same location
- Notice they're at the same address

### 01-array-vs-pointer.c
Shows all four equivalent ways to access elements:
1. `arr[i]` - classic array syntax
2. `*(arr + i)` - pointer arithmetic
3. `ptr[i]` - pointer with subscript
4. `*(ptr + i)` - pointer arithmetic

**Python Tutor Focus:**
- All four variables get the same value (30)
- Different roads, same destination

### 02-string-manipulation.c
Practical example: counting string length
- Strings are just char arrays
- Walk through with pointer
- Find null terminator `'\0'`

**Python Tutor Focus:**
- Watch `ptr` move through each character
- See `len` count up
- Notice when it hits `'\0'` and stops

## Understanding Strings

### String Basics
A string in C is:
- An array of `char`
- Ending with `'\0'` (null terminator)

```c
char str[] = "Hi";
// Actually stored as: {'H', 'i', '\0'}
```

### Why Null Terminator?
C needs to know where the string ends:
```c
char str[] = "42";
// Memory: ['4']['2']['\0']
//                      ↑
//              This tells C: "string ends here"
```

### Common String Operations with Pointers

**Length:**
```c
int len = 0;
char *ptr = str;
while (*ptr != '\0')
{
    len++;
    ptr++;
}
```

**Copy:**
```c
char *src = "Hello";
char dest[6];
int i = 0;
while (src[i] != '\0')
{
    dest[i] = src[i];
    i++;
}
dest[i] = '\0';
```

## The Equivalence Table

| Array Notation | Pointer Notation | Meaning |
|---------------|------------------|---------|
| `arr[0]` | `*arr` or `*(arr + 0)` | First element |
| `arr[1]` | `*(arr + 1)` | Second element |
| `arr[i]` | `*(arr + i)` | i-th element |
| `&arr[0]` | `arr` | Address of first element |
| `&arr[i]` | `arr + i` | Address of i-th element |

## Practice Exercises

1. **String Length**
   - Write a function that counts characters in a string
   - Use only pointers, no array indexing
   - Don't count the null terminator

2. **String Copy**
   - Copy one string to another
   - Use pointer notation only
   - Don't forget the null terminator!

3. **Find Character**
   - Search for a specific character in a string
   - Return pointer to that character
   - Return NULL if not found

4. **Reverse String**
   - Create two pointers: start and end
   - Swap characters while moving towards middle
   - Use pointer arithmetic

## Important Rules

### What Arrays and Pointers Share:
- Both can use `[]` subscript notation
- Both can use pointer arithmetic
- Both can be dereferenced with `*`

### Key Differences:

| Feature | Array | Pointer |
|---------|-------|---------|
| Size | Fixed at declaration | No size |
| Reassignment | Cannot reassign | Can reassign |
| `sizeof()` | Size of entire array | Size of pointer (8 bytes on 64-bit) |
| Initialization | `int arr[5];` | `int *ptr;` |

## Common Mistakes

❌ **Forgetting null terminator:**
```c
char str[3];
str[0] = 'H';
str[1] = 'i';
// Missing: str[2] = '\0';
// Functions expecting string will go past end!
```

❌ **Confusing array size:**
```c
int arr[5];
sizeof(arr);  // 20 (5 * sizeof(int))

int *ptr = arr;
sizeof(ptr);  // 8 (size of pointer, not array!)
```

❌ **String literals are read-only:**
```c
char *str = "Hello";
str[0] = 'h';  // CRASH! String literal is read-only
```

✅ **Correct:**
```c
char str[] = "Hello";  // Creates modifiable array
str[0] = 'h';          // OK!
```

## 42 School Tips

### Common Tasks:
- **ft_strlen**: Use pointer to count until `'\0'`
- **ft_strcpy**: Use two pointers, copy until `'\0'`
- **ft_strcmp**: Compare characters at each position
- **ft_strcat**: Find end of dest, then copy src

### Exam Strategy:
1. Start with array notation if easier
2. Convert to pointers once working
3. Test with strings of different lengths
4. Always handle empty strings (`""`)
5. Don't forget the null terminator!

## Next Steps
Continue to **03-pointers-and-functions** to learn:
- Pass by reference
- Modifying variables through function parameters
- Passing arrays to functions
