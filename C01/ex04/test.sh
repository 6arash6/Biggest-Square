#!/bin/sh
# Test for ex04/ft_ultimate_div_mod.c
cat > main.c <<EOF
#include <stdio.h>
void ft_ultimate_div_mod(int *a, int *b);
int main(void) {
  int a = 10, b = 3;
  ft_ultimate_div_mod(&a, &b);
  printf("%d %d\n", a, b);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_ultimate_div_mod.c main.c -o test_ft_ultimate_div_mod
output=$(./test_ft_ultimate_div_mod)
expected="3 1"
echo "Test: ft_ultimate_div_mod(&a, &b)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_ft_ultimate_div_mod
