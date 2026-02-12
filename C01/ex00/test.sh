#!/bin/sh
# Test for ex00/ft_ft.c
cc -Wall -Wextra -Werror ft_ft.c -o test_ft_ft -DTEST_MAIN
cat > main.c <<EOF
#include <stdio.h>
void ft_ft(int *nbr);
int main(void) {
  int x = 0;
  ft_ft(&x);
  printf("%d\n", x);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_ft.c main.c -o test_ft_ft
output=$(./test_ft_ft)
expected="42"
echo "Test: ft_ft(&x)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_ft_ft
