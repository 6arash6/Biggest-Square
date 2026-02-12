#!/bin/sh
# Test for ex07/ft_putnbr.c
cc -Wall -Wextra -Werror ft_putnbr.c -o test_putnbr
cat > main.c <<EOF
void ft_putnbr(int nb);
int main(void) {
  ft_putnbr(-42);
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_putnbr.c main.c -o test_putnbr
output=$(./test_putnbr | cat -e)
expected="-42$"
echo "Test: ft_putnbr(-42)"
echo "Expected: $expected"
echo -n "Actual:   "
./test_putnbr | cat -e
echo
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_putnbr
