#!/bin/sh
# Test for ex02/ft_ultimate_ft.c
cat > main.c <<EOF
#include <stdio.h>
void ft_ultimate_ft(int *********nbr);
int main(void) {
  int x = 0;
  int *p1 = &x, **p2 = &p1, ***p3 = &p2, ****p4 = &p3, *****p5 = &p4, ******p6 = &p5, *******p7 = &p6, ********p8 = &p7, *********p9 = &p8;
  ft_ultimate_ft(p9);
  printf("%d\n", x);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_ultimate_ft.c main.c -o test_ft_ultimate_ft
output=$(./test_ft_ultimate_ft)
expected="42"
echo "Test: ft_ultimate_ft(&p9)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_ft_ultimate_ft
