#!/bin/sh
# Test for ex05/ft_print_comb.c
cat > main.c <<EOF
void ft_print_comb(void);
int main(void) {
  ft_print_comb();
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_print_comb.c main.c -o test_print_comb
output=$(./test_print_comb | cat -e)
expected_prefix="012, 013, 014"
echo "Test: ft_print_comb()"
echo "Expected prefix: $expected_prefix"
echo -n "Actual:   "
./test_print_comb | head -n 1 | cat -e
# Only check prefix for brevity
echo "$output" | grep -q "$expected_prefix"
if [ $? -eq 0 ]; then
  echo "PASS (prefix matches)"
else
  echo "FAIL"
fi
rm -f main.c test_print_comb
