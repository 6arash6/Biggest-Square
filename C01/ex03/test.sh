#!/bin/sh
# Test for ex03/ft_div_mod.c
cat > main.c <<EOF
#include <stdio.h>
void ft_div_mod(int a, int b, int *div, int *mod);
int main(void) {
  int div = 0, mod = 0;
  ft_div_mod(10, 3, &div, &mod);
  printf("%d %d\n", div, mod);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_div_mod.c main.c -o test_ft_div_mod
output=$(./test_ft_div_mod)
expected="3 1"
echo "Test: ft_div_mod(10, 3, &div, &mod)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_ft_div_mod
