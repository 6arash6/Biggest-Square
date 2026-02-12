#!/bin/sh
# Test for ex06/ft_print_comb2.c
cat > main.c <<EOF
void ft_print_comb2(void);
int main(void) {
  ft_print_comb2();
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_print_comb2.c main.c -o test_print_comb2
output=$(./test_print_comb2 | cat -e)
expected_prefix="00 01, 00 02, 00 03"
echo "Test: ft_print_comb2()"
echo "Expected prefix: $expected_prefix"
echo -n "Actual:   "
./test_print_comb2 | head -n 1 | cat -e
# Only check prefix for brevity
echo "$output" | grep -q "$expected_prefix"
if [ $? -eq 0 ]; then
  echo "PASS (prefix matches)"
else
  echo "FAIL"
fi
rm -f main.c test_print_comb2
