#!/bin/sh
# Test for ex03/ft_strlcat.c
cc -Wall -Wextra -Werror ft_strlcat.c main.c -o test_strlcat
output=$(./test_strlcat)
expected="Piscine42\n9"
echo "Test: ft_strlcat("Piscine", "42", 100)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
