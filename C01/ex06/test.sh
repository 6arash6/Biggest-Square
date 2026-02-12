#!/bin/sh
# Test for ex06/ft_strlen.c
cc -Wall -Wextra -Werror ft_strlen.c -o test_strlen
cat > main.c <<EOF
#include <stdio.h>
int ft_strlen(char *str);
int main(void) {
  printf("%d\n", ft_strlen("Hello"));
  return 0;
}
EOF
cc -Wall -Wextra -Werror ft_strlen.c main.c -o test_strlen
output=$(./test_strlen)
expected="5"
echo "Test: ft_strlen(\"Hello\")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
rm -f main.c test_strlen
