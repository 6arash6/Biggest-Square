#!/bin/sh
# Test for ex05/ft_putstr.c
cc -Wall -Wextra -Werror ft_putstr.c -o test_putstr
cat > main.c <<EOF
void ft_putstr(char *str);
int main(void) {
  ft_putstr("Hello, 42!");
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_putstr.c main.c -o test_putstr
output=$(./test_putstr | cat -e)
expected="Hello, 42!$"
echo "Test: ft_putstr(\"Hello, 42!\")"
echo "Expected: $expected"
echo -n "Actual:   "
./test_putstr | cat -e
echo
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_putstr
