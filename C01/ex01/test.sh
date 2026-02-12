#!/bin/sh
# Test for ex01/ft_swap.c
cat > main.c <<EOF
#include <stdio.h>
void ft_swap(int *a, int *b);
int main(void) {
  int x = 1, y = 2;
  ft_swap(&x, &y);
  printf("%d %d\n", x, y);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_swap.c main.c -o test_ft_swap
output=$(./test_ft_swap)
expected="2 1"
echo "Test: ft_swap(&x, &y)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_ft_swap
