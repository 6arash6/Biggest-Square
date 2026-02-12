#!/bin/sh
# Test for ex00/ft_putchar.c
cat > main.c <<EOF
#include <unistd.h>
void ft_putchar(char c);
int main(void) {
  ft_putchar('A');
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_putchar.c main.c -o test_putchar
output=$(./test_putchar | cat -e)
expected="A$"
echo "Test: ft_putchar('A')"
echo "Expected: $expected"
echo -n "Actual:   "
./test_putchar | cat -e
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_putchar
