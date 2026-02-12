#!/bin/sh
# Test for ex04/ft_is_negative.c
cat > main.c <<EOF
void ft_is_negative(int n);
int main(void) {
  ft_is_negative(1);
  ft_is_negative(-1);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_is_negative.c main.c -o test_is_negative
output=$(./test_is_negative | cat -e)
expected="PN$"
echo "Test: ft_is_negative(1); ft_is_negative(-1);"
echo "Expected: $expected"
echo -n "Actual:   "
./test_is_negative | cat -e
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_is_negative
