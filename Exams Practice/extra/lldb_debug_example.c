// lldb_debug_example.c
// Example with pointer, array, string, and a bug to debug with LLDB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n = 5;
    int *arr = malloc(n * sizeof(int));
    if (!arr) return 1;
    for (int i = 0; i <= n; i++) // BUG: should be i < n
        arr[i] = i * 2;
    print_array(arr, n);

    char str[10] = "hello";
    char *p = str;
    for (int i = 0; i < 10; i++) {
        if (p[i] >= 'a' && p[i] <= 'z')
            p[i] -= 32; // to uppercase
    }
    printf("%s\n", str);

    free(arr);
    return 0;
}

/*
LLDB Debugging Steps:
1. Compile: gcc -g lldb_debug_example.c -o lldb_debug_example
2. Start: lldb ./lldb_debug_example
3. (lldb) break main
4. (lldb) run
5. (lldb) next / step through code
6. (lldb) print arr, print str, print p
7. (lldb) bt (if crash)
8. Find the bug: arr[i] = ... (out-of-bounds)
*/
