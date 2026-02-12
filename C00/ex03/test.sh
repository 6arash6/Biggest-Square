#!/bin/sh
# Test for ex03/ft_print_numbers.c
cat > main.c <<EOF
void ft_print_numbers(void);
int main(void) {
  ft_print_numbers();
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_print_numbers.c main.c -o test_print_numbers
output=$(./test_print_numbers | cat -e)
expected="0123456789$"
echo "Test: ft_print_numbers()"
echo "Expected: $expected"
echo -n "Actual:   "
./test_print_numbers | cat -e
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_print_numbers
