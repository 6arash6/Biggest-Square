#!/bin/sh
# Test for ex08/ft_sort_int_tab.c
cat > main.c <<EOF
#include <stdio.h>
void ft_sort_int_tab(int *tab, int size);
int main(void) {
  int arr[5] = {5, 2, 4, 1, 3};
  ft_sort_int_tab(arr, 5);
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_sort_int_tab.c main.c -o test_sort_int_tab
output=$(./test_sort_int_tab)
expected="1 2 3 4 5 "
echo "Test: ft_sort_int_tab([5,2,4,1,3], 5)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_sort_int_tab
