#!/bin/sh
# Test for ex01/ft_print_alphabet.c
cat > main.c <<EOF
void ft_print_alphabet(void);
int main(void) {
  ft_print_alphabet();
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_print_alphabet.c main.c -o test_print_alphabet
output=$(./test_print_alphabet | cat -e)
expected="abcdefghijklmnopqrstuvwxyz$"
echo "Test: ft_print_alphabet()"
echo "Expected: $expected"
echo -n "Actual:   "
./test_print_alphabet | cat -e
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_print_alphabet
