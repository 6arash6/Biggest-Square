#!/bin/sh
# Test for ex08/ft_print_combn.c
cat > main.c <<EOF
void ft_print_combn(int n);
int main(void) {
  ft_print_combn(2);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_print_combn.c main.c -o test_print_combn
output=$(./test_print_combn | cat -e)
expected_prefix="01, 02, 03"
echo "Test: ft_print_combn(2)"
echo "Expected prefix: $expected_prefix"
echo -n "Actual:   "
./test_print_combn | head -n 1 | cat -e
# Only check prefix for brevity
echo "$output" | grep -q "$expected_prefix"
if [ $? -eq 0 ]; then
  echo "PASS (prefix matches)"
else
  echo "FAIL"
fi
rm -f main.c test_print_combn
