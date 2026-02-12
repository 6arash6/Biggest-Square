#!/bin/sh
# Test for ex02/ft_print_reverse_alphabet.c
cat > main.c <<EOF
void ft_print_reverse_alphabet(void);
int main(void) {
  ft_print_reverse_alphabet();
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_print_reverse_alphabet.c main.c -o test_print_reverse_alphabet
output=$(./test_print_reverse_alphabet | cat -e)
expected="zyxwvutsrqponmlkjihgfedcba$"
echo "Test: ft_print_reverse_alphabet()"
echo "Expected: $expected"
echo -n "Actual:   "
./test_print_reverse_alphabet | cat -e
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_print_reverse_alphabet
